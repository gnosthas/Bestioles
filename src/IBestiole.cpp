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



///////////// Initialise la bestiole : Id, position, vitesse, couleur, ... /////////////////
void IBestiole::initBestiole(){
   this->identite = ++next;
   this->x = this->y = 0;
   this->cumulX = this->cumulY = 0.;
   //Orientation initiale aléatoire
   this->orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   // vitesse initiale aléatoire
   this->vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   // définit la couleur de la bestiole r , g , b
   couleur = comportement->getCouleur();

   // this->proba_death = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   this->proba_death = 0.1;
   this->duree_vie = 200 + rand() % 201; // Durée de vie entre 200 et 400 aléatoire
   this->proba_clone= 0.003; 
   bool capteursInit = 0;
   this->genererCapteurs();
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

///////////////////////// Constructeur d'une bestiole /////////////////////////////

////////// TEMPORAIRE POUR TEST COMPILATION

IBestiole::IBestiole(Milieu& milieu, IComportement* comportement) : milieu(milieu), comportement(comportement){

   initBestiole();
   this->ajout_Accessoires();
   // switch (comportement->getComportementType())
   // {
   // couleur en fonction du comportement ? setColor(r,g,b) mais il faut un enumtype des comportements !
   // }
}

IBestiole::IBestiole(Milieu &milieu): milieu(milieu){
   initBestiole();
   this->ajout_Accessoires();
 
}

///////////////////////// Constructeur par copie de la bestiole /////////////////////////////


IBestiole::IBestiole( const IBestiole & ib) : identite(++next), x(ib.x), y(ib.y), 
cumulX(ib.cumulX), cumulY(ib.cumulY), vitesse(ib.vitesse), orientation(ib.orientation), 
proba_death(ib.proba_death), proba_clone(ib.proba_clone),comportement(ib.comportement), milieu(ib.milieu)//, listAccessoires(listAccessoires)
{
   cout << "const IBestiole (" << this->identite << ") par copie" << endl;
   duree_vie = 200 + rand() % 201; // Il faut réinitialiser la durée de vie sinon la bestiole clonnée meurt en meme temps que sa version originale
   couleur = new T[ 3 ];
   memcpy( couleur, ib.couleur, 3*sizeof(T) );
   this->duree_vie = 200 + rand() % 201;

   this->ajout_Accessoires();
}

///////////////////////// Destructeur /////////////////////////////
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
////////////////// Initialise aléatoire la position de la bestiole ///////////////
void IBestiole::initCoords( int xLim, int yLim )
{
   this->x = rand() % xLim;
   this->y = rand() % yLim;
}

////////////////////// Est-ce nécessaire ou alors le faire dans bestiole car on n'instancie pas de IBestiole ?////////////////////
bool operator==( const IBestiole & ib1, const IBestiole & ib2 )
{
   return ( ib1.identite == ib2.identite );
}

void IBestiole::decrDureeVie(){
   -- this->duree_vie;
}

/// Savoir si la bestiole passée en argument est dans le champ de vision de la bestiole courante ///
bool IBestiole::jeTeVois( const IBestiole & ib ) const
{
   double         distance_bestioles;
   distance_bestioles = sqrt( pow(x-ib.x,2)+ pow(y-ib.y,2) );
   return ( distance_bestioles <= LIMITE_VUE );
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

//Pour créer des bestioles différentes en fonction de leur couleur
void IBestiole::setColor(int r, int g, int b){
   this->couleur[0] = r;
   this->couleur[1] = g;
   this->couleur[2] = b;
}

void IBestiole::setX(int x){
   this->x =x;
   }
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

////////////////////////Les Méthodes qu'il reste à implémenter ////////////////

 ///////////////////////////// Déplacement de la bestiole dans le milieu ////////////////////////
// void IBestiole::bouge(Milieu &milieu){
//    comportement->bougeSelonComportement(milieu, &this);
// }

//////////////// Méthode appelée sur la bestiole à chaque pas de simulation /////////////////////////
void IBestiole::action(std::vector<IBestiole*> & appendBestioles, std::vector<IBestiole*> & removeBestioles){ 

   ///////// Clonage /////////////
   double clonnage = ((rand() % 1001) + 1) / 1000.0;
   if(clonnage <= this->proba_clone){
      IBestiole* best_clone = clone(); 
      appendBestioles.push_back(best_clone);
   }
   
   bouge();
   
   ///////// Collision ////////////
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


//////////////////////////// Affichage d'une créature /////////////////////////////////////////
// void IBestiole::draw( UImg & support, Milieu & milieu ){

//    double         xt = x + cos( orientation )*AFF_SIZE/2.1;
//    double         yt = y - sin( orientation )*AFF_SIZE/2.1;


//    support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
//    support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

// }; 

////////// TEMPORAIRE POUR TEST COMPILATION
void IBestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}




// IL FAUT REUSSIR A PASSER UNE REFERENCE AU MILIEU À L'INIT DE CHAQUE IBESTIOLE POUR QUE CELA MARCHE
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


void IBestiole::collision(vector<IBestiole*> & removeBestioles){
   vector<IBestiole*>& bestioles = milieu.getListeBestiole(); 
   double         distance_bestioles;
   for (auto it = bestioles.begin() ; it != bestioles.end() ; ++it)
   {
      if(*it != this)
      {
         distance_bestioles = sqrt( pow(this->x-(*it)->x,2)+ pow(this->y-(*it)->y,2) );
         
         if (distance_bestioles <= AFF_SIZE) 
         {
            double proba_survive = (rand() % 101)/100.0;            

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







