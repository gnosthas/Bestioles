#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>

#include "Milieu.h"
#include "IBestiole.h"
#include "comportements/IComportement.h"
#include "Accessoires/IAccessoire.h"
#include "Accessoires/Nageoire.h"
#include "Capteurs/capteur.h"
#include "Capteurs/capteurFactory.h"

#include <cstdlib>
#include <cmath>

using namespace std;

const double      IBestiole::AFF_SIZE = 8.0;
const double      IBestiole::MAX_VITESSE = 10.0;
const double      IBestiole::LIMITE_VUE = 30.0;

int               IBestiole::next = 0;

//Constructeur 
IBestiole::IBestiole(Milieu& milieu, IComportement* comportement) : milieu(milieu), comportement(comportement){
   initBestiole();
   this->ajout_Accessoires();
}

//Constructeur par copie
IBestiole::IBestiole( const IBestiole & ib) : identite(++next), x(ib.x), y(ib.y), 
cumulX(ib.cumulX), cumulY(ib.cumulY), vitesse(ib.vitesse), orientation(ib.orientation), 
proba_death(ib.proba_death), proba_clone(ib.proba_clone),comportement(ib.comportement), milieu(ib.milieu)//, listAccessoires(listAccessoires)
{
   //cout << "const IBestiole (" << this->identite << ") par copie" << endl;
   
   /*On fait le choix de réinitialiser la durée de vie lors du clonage sinon la bestiole clonnée 
   meurt en meme temps que sa version originale, ce qui provoque des "sauts" dans la simulation*/
   duree_vie = 200 + rand() % 201; 
   couleur = new T[ 3 ];
   memcpy( couleur, ib.couleur, 3*sizeof(T) );
   this->duree_vie = 200 + rand() % 201;

   this->ajout_Accessoires();
}

//Destructeur
IBestiole::~IBestiole( void )
{
   cout << "dest IBestiole" << endl;
      
   for (IAccessoire* a : this->listAccessoires) {
      delete a;
   }
   
   for (ICapteur* c : this->listCapteurs) {
      delete c;
   }
   // this->listCapteurs.clear();

   //delete[] this->couleur;
   //delete this->comportement; //Warning Segment error ===> C'est normal : on a cette erreur car les comportements ne sont pas associé à une bestiole en particulier.
   
}

//Initialise la bestiole : (Id, position, vitesse, ...) - Appelée dans le Constructeur
void IBestiole::initBestiole(){
   this->identite = ++next;
   this->x = this->y = 0;
   this->cumulX = this->cumulY = 0.;
   //Orientation initiale aléatoire
   this->orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   // vitesse initiale aléatoire
   this->vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = comportement->getCouleur();

   // this->proba_death = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   this->proba_death = 0.1; 
   this->duree_vie = 200 + rand() % 201; // Durée de vie entre 200 et 400 aléatoire
   this->proba_clone= 0.003; 
   this->genererCapteurs();
   /*Probabilités de mort et de clonage fixées à 0.1 et 0.003 pour des raisons 
   d'autorégulation de la population lors de la simulation. Une initialisation aléatoire fonctionne
   parfaitement mais est moins pertinente pour l'observation d'une simulation. */
}


void IBestiole::ajout_Accessoires(){
   // Ajout de nageoires avec une probabilité de 10%
   int rand_nag = rand() % 100;
   if (rand_nag <= 10){
      // this->has_nageoires = true;
      Nageoire* nageoire = this->milieu.createNageoire();
      listAccessoires.push_back(nageoire);
      this->vitesse = this->vitesse * nageoire->getMultvitesse();
   }else{
      // this->has_nageoires=false;
      listAccessoires.push_back(nullptr);
   }

   // Ajout d'une carapace avec une probabilité de 10%
   int rand_car = rand() % 100;
   if (rand_car <= 10){
      // this->has_carapace = true;
      Carapace* carapace = this->milieu.createCarapace();
      
      listAccessoires.push_back(carapace);
      this->vitesse = this->vitesse / carapace->getReducVitesse();
      this->proba_death = this->proba_death / carapace->getResistance();
   }
   else{
      // this->has_carapace = true;
      listAccessoires.push_back(nullptr);
   }


}

////Place la bestiole à un endroit aléatoire avec limite horyzontale & verticale
void IBestiole::initCoords( int xLim, int yLim )
{
   this->x = rand() % xLim;
   this->y = rand() % yLim;
}

//Surcharge de l'opérateur pour test d'égalité entre deux bestioles
bool operator==( const IBestiole & ib1, const IBestiole & ib2 )
{
   return ( ib1.identite == ib2.identite );
}

void IBestiole::decrDureeVie(){
   -- this->duree_vie;
}

//Détermine si la bestiole détecte la bestiole passée en argument
bool IBestiole::jeTeVois( const IBestiole & ib ) const
{
   double         distance_bestioles;
   distance_bestioles = sqrt( pow(x-ib.x,2)+ pow(y-ib.y,2) );
   return ( distance_bestioles <= LIMITE_VUE );
}

//Réalise le clonage, la collision et le mouvement des Bestioles
void IBestiole::action(std::vector<IBestiole*> & appendBestioles, std::vector<IBestiole*> & removeBestioles){ 

   //Clonage aléatoire d'une Bestiole
   double clonnage = ((rand() % 1001) + 1) / 1000.0;
   if(clonnage <= this->proba_clone){
      IBestiole* best_clone = clone(); 
      appendBestioles.push_back(best_clone);
   }
   //Mouvement
   bouge();
   
   //Collision 
   collision(removeBestioles);
   
   decrDureeVie();

   if (this->getDureeVie() == 0)
   {  
   // On utilise find pour vérifier que la bestiole qui meurt de vieillesse n'est pas déjà morte de collision
      if(find(removeBestioles.begin(),removeBestioles.end(),this) == removeBestioles.end())
      {
         removeBestioles.push_back(this);
         cout << "Une bestiole va mourrir de vieillesse" << endl;
      }
   }
}; 

/*Gère la Collision entre les Bestioles : On va remplir une liste removeBestioles à supprimer de
l'environnement dans le cas d'une collision mortelle pour la Bestiole courante et dans le cas
contraire, inverser la direction de la Bestiole*/
void IBestiole::collision(std::vector<IBestiole*> & removeBestioles){
   std::vector<IBestiole*>& bestioles = milieu.getListeBestiole(); 
   double         distance_bestioles;
   for (auto it = bestioles.begin() ; it != bestioles.end() ; ++it) //Parcours des Bestioles du milieu
   {
      if(*it != this) //On ne considère pas l'interraction de la Bestiole avec elle-même
      {
         distance_bestioles = sqrt( pow(this->x-(*it)->x,2)+ pow(this->y-(*it)->y,2) );
         
         if (distance_bestioles <= AFF_SIZE) //Choix simple et naïf de considérer simplement le diamètre pour la collision
         {
            double proba_survive = (rand() % 101)/100.0;
            double proba_death = this->get_proba_death();

            if (proba_death > proba_survive) //Si la proba de mort est supérieure à la proba de survie tirée aléatoirement
            {
               removeBestioles.push_back(this);
               cout << "Une Bestiole va mourrir de collision" << endl;
            }
            this-> orientation = - orientation;
         }
      }

   } 

};


//Affichage d'une créature
void IBestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}

void IBestiole::genererCapteurs(){

   listCapteurs.push_back(this->milieu.createCapteur(TC_Corps));
   int n = rand() % 4;
   switch(n){
      case 0 :
         listCapteurs.push_back(this->milieu.createCapteur(TC_Oreilles));
         std::cout<<"Bestiole avec des oreilles"<<std::endl;
         break;
      case 1 :
         listCapteurs.push_back(this->milieu.createCapteur(TC_Yeux));
         std::cout<<"Bestiole avec des yeux"<<std::endl;
         break;
      case 2 : 
         listCapteurs.push_back(this->milieu.createCapteur(TC_Yeux));
         listCapteurs.push_back(this->milieu.createCapteur(TC_Oreilles));
         std::cout<<"Bestiole avec des oreilles ET des yeux"<<std::endl;
         break;
      case 3 :
         std::cout<<"Bestiole sans capteurs :("<<std::endl;
         break;
   }

}

///////////////////////////// GETTEURS ///////////////////////////////////
int IBestiole::getX() const {return x;}
int IBestiole::getY() const {return y;}
int IBestiole::getIdentite() const {return this->identite;}
int IBestiole::getDureeVie() const{return this->duree_vie;};
IComportement* IBestiole::getComportement() const {return this->comportement;}
double IBestiole::get_proba_death() const{return this->proba_death;}
double IBestiole::get_vitesse() const{return this-> vitesse;}
double IBestiole::getCumulX() const{return this-> cumulX;}
double IBestiole::getCumulY() const{return this-> cumulY;}
double IBestiole::getOrientation() const{return this->orientation;}


/////////////////////////////////SETTEURS //////////////////////////////

void IBestiole::setVitesse(double v){
   this->vitesse = v;
};

void IBestiole::setColor(int r, int g, int b){
   this->couleur[0] = r;
   this->couleur[1] = g;
   this->couleur[2] = b;
}

void IBestiole::setX(int x){this->x =x;}
void IBestiole::setY(int y){this->y =y;}
void IBestiole::setCumulX(double cx){this->cumulX = cx;}
void IBestiole::setCumulY(double cy){this->cumulY = cy;}
void IBestiole::setDureeVie(int duree_vie){this->duree_vie = duree_vie;};
void IBestiole::setOrientation(double o){
   if (o > 2*M_PI) {
      double intpart,fracpart;
      fracpart = std::modf(o/(2*M_PI), &intpart);
      o = 2*M_PI*fracpart;
   } 
   this->orientation =o;
   }
