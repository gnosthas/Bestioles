#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>

#include "Milieu.h"
#include "IBestiole.h"
#include "comportements/IComportement.h"
#include "Accessoires/IAccessoire.h"
#include "Accessoires/ConcreteCreatorNageoire.h"

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
   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   // this->proba_death = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   this->proba_death = 0.1;
   this->duree_vie = 200 + rand() % 201; // Durée de vie entre 200 et 400 aléatoire
   this->proba_clone= 0.003; 
   std::vector<IAccessoire*> listAccessoires = this->ajout_Accessoires();
}


std::vector<IAccessoire*> IBestiole::ajout_Accessoires(){
   std::vector<IAccessoire*> listAccessoires;
   int rand_nag = rand() % 100;
   if (rand_nag <= 5){
      ConcreteCreatorNageoire creator_nageoire;
      Nageoire* nageoire = creator_nageoire.createAccessoire();
      listAccessoires.push_back(nageoire);
      this->vitesse = this->vitesse * nageoire->getMultvitesse();
   }
   return listAccessoires;
}

///////////////////////// Constructeur d'une bestiole /////////////////////////////

////////// TEMPORAIRE POUR TEST COMPILATION

IBestiole::IBestiole(IComportement* comportement) : comportement(comportement){

   initBestiole();
   // switch (comportement->getComportementType())
   // {
   // couleur en fonction du comportement ? setColor(r,g,b) mais il faut un enumtype des comportements !
   // }
}

IBestiole::IBestiole(){
   initBestiole();
}

///////////////////////// Constructeur par copie de la bestiole /////////////////////////////

////////// TEMPORAIRE POUR TEST COMPILATION
// IBestiole::IBestiole( const IBestiole & b )
// {

//    identite = ++next;

//    cout << "const Bestiole (" << identite << ") par copie" << endl;

//    x = b.x;
//    y = b.y;
//    cumulX = cumulY = 0.;
//    orientation = b.orientation;
//    vitesse = b.vitesse;
//    couleur = new T[ 3 ];
//    memcpy( couleur, b.couleur, 3*sizeof(T) );

// }

IBestiole::IBestiole( const IBestiole & ib ) : identite(++next), x(ib.x), y(ib.y), 
cumulX(ib.cumulX), cumulY(ib.cumulY), vitesse(ib.vitesse), orientation(ib.orientation), 
proba_death(ib.proba_death), duree_vie(ib.duree_vie), proba_clone(ib.proba_clone),comportement(ib.comportement)
{
   cout << "const IBestiole (" << this->identite << ") par copie (last en date)" << endl;
   couleur = new T[ 3 ];
   memcpy( couleur, ib.couleur, 3*sizeof(T) );
}

///////////////////////// Destructeur /////////////////////////////
IBestiole::~IBestiole( void )
{
   cout << "dest IBestiole" << endl;
   delete[] this->couleur;
   
   for (IAccessoire* a : this->listAccessoires) {
      delete a;
   }
   this->listAccessoires.clear();
   //delete this->comportement; //Warning Segment error
   
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
void IBestiole::action(Milieu & milieu, std::vector<IBestiole*> & appendBestioles, std::vector<IBestiole*> & removeBestioles){ 

   ///////// Clonage /////////////
   double clonnage = ((rand() % 1001) + 1) / 1000.0;
   if(clonnage <= this->proba_clone){
      IBestiole* best_clone = clone(); 
      appendBestioles.push_back(best_clone);
   }
   
   bouge(milieu);
   
   ///////// Collision ////////////
   collision(milieu, removeBestioles);
   
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





 /*Gère la collision entre les créatures. La collision se fait entre deux cercles ? deux ellipses ?
   Parcours la liste de toutes les autres créatures ?
   En cas de collision, 1] proba mort 2] changement d'orientation à l'opposée */

void IBestiole::collision(Milieu &milieu, std::vector<IBestiole*> & removeBestioles){
   std::vector<IBestiole*>& bestioles = milieu.getListeBestiole(); 
   double         distance_bestioles;
   for (auto it = bestioles.begin() ; it != bestioles.end() ; ++it)
   {
      if(*it != this)
      {
         distance_bestioles = sqrt( pow(this->x-(*it)->x,2)+ pow(this->y-(*it)->y,2) );
         
         if (distance_bestioles <= AFF_SIZE) 
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







