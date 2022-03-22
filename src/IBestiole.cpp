#include <iostream>
#include <vector>

// #include "comportements/IComportement.h"
#include "Milieu.h"
#include "UImg.h"
#include "IBestiole.h"

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

   this->proba_death = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   this->age = 0; //Toute bestiole même durée de vie du coup ? ou alors crée champ durée de vie et on l'initialise aléatoirement puis il décroit à chaque pas de simul
   this->proba_clone= 0.01; 
}

///////////////////////// Constructeur d'une bestiole /////////////////////////////

////////// TEMPORAIRE POUR TEST COMPILATION

// IBestiole::IBestiole(IComportement* comportement) : comportement(comportement){

//    initBestiole();
//    switch (comportement->getComportementType())
//    {
//    // couleur en fonction du comportement ? setColor(r,g,b) mais il faut un enumtype des comportements !
// }
// }

IBestiole::IBestiole(){
   initBestiole();
}

///////////////////////// Constructeur par copie de la bestiole /////////////////////////////

////////// TEMPORAIRE POUR TEST COMPILATION
IBestiole::IBestiole( const IBestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}

// IBestiole::IBestiole( const IBestiole & ib ) : identite(++next), x(ib.x), y(ib.y), 
// cumulX(ib.cumulX), cumulY(ib.cumulY), vitesse(ib.vitesse), orientation(ib.orientation), 
// proba_death(ib.proba_death), age(ib.age), proba_clone(ib.proba_clone), listCapteurs(ib.listCapteurs),
//  listAccessoires(ib.listAccessoires),comportement(ib.comportement)
// {
//    cout << "const IBestiole (" << this->identite << ") par copie" << endl;
//    couleur = new T[ 3 ];
//    memcpy( couleur, ib.couleur, 3*sizeof(T) );
// }

///////////////////////// Destructeur /////////////////////////////
IBestiole::~IBestiole( void )
{
   cout << "dest IBestiole" << endl;
   delete[] this->couleur;
   ////////// TEMPORAIRE POUR TEST COMPILATION
   // delete this->comportement;
   
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
int IBestiole::getAge() const{return this->age;};
// IComportement* IBestiole::getComportement() const {return this->comportement;}
double IBestiole::get_proba_death() const{return this->proba_death;}
double IBestiole::get_vitesse() const{return this-> vitesse;}
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


////////////////////////Les Méthodes qu'il reste à implémenter ////////////////

 ///////////////////////////// Déplacement de la bestiole dans le milieu ////////////////////////
void IBestiole::bouge(Milieu &milieu){
   double         nx, ny;
   int            cx, cy;
   int xLim = milieu.getWidth();
   int yLim = milieu.getHeight();

   double         dx = cos( orientation )*vitesse; // A vérifier ce déplacement
   double         dy = -sin( orientation )*vitesse;

   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

//////////////// Méthode appelée sur la bestiole à chaque pas de simulation /////////////////////////
void IBestiole::action(Milieu & milieu ){ 

   ///////// Clonage /////////////
   bouge(milieu);

   ///////// Collision ////////////
   collision(milieu);
   incr_age();
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
void IBestiole::collision(Milieu &milieu){
   //if (distance_bestioles <= AFF_SIZE) 
     //    {
         //   this-> orientation = - orientation;
       //  }
};


void IBestiole::genererCapteurs(Milieu & monMilieu){
   listCapteurs.push(monMilieu.createCapteur(TC_Corps));
   int n = rand() % 2;
   switch(n){
      case 0 :
         listCapteurs.push(monMilieu.createCapteur(TC_Oreilles));
         break;
      case 1 :
         listCapteurs.push(monMilieu.createCapteur(TC_Yeux));
         break;
      case 2 : 
         listCapteurs.push(monMilieu.createCapteur(TC_Yeux));
         listCapteurs.push(monMilieu.createCapteur(TC_Oreilles));
         break;
   }

}










