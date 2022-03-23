#include "Milieu.h"
#include "IBestiole.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementGregaire.h"
#include "comportements/ComportementKamikaze.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementPrevoyante.h"
#include "comportements/ComportementPersMultiple.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height, int nb_Bestioles, double Greg, 
double Peur, double Kamik, double Prev, double Mult ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height),
                                            nb_Bestioles(nb_Bestioles), propGreg(Greg),
                                            propPeur(Peur), propKamik(Kamik), propPrev(Prev), propMult(Mult)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{  
   for (IBestiole* b : listeBestioles) {
      delete b;
   }
   listeBestioles.clear();
   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   std::vector<IBestiole*> appendBestioles; //Bestioles à ajouter à chaque pas de simulation
   std::vector<IBestiole*> removeBestioles; //Bestioles à retirer à chaque pas de simulation

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   for (auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it)
   {  
      (*it)->action(*this, appendBestioles, removeBestioles);
      (*it)->draw( *this );
   }
   if(!appendBestioles.empty()){ 
      for(auto it = appendBestioles.begin() ; it != appendBestioles.end() ; ++it){
         addBestiole(*it);
         cout << "ADDED BESTIOLE" << endl;
      }
   }
   if(!removeBestioles.empty()){ 
      for(auto it = removeBestioles.begin() ; it != removeBestioles.end() ; ++it){
         removeBestiole(*it);
         cout << "REMOVED BESTIOLE" << endl;
      }
   }
      
   std::random_device dev;
   std::mt19937 rng(dev());
   std::uniform_int_distribution<std::mt19937::result_type> proba_naiss_sponta(0,100);
   if (proba_naiss_sponta(rng) < 3) //On considère un taux prédéfini de 3% de naissance
   {
      this->naissanceSpontanee();
      cout << "Naissance spontanée d'une Bestiole"<<endl;
   }
}


int Milieu::nbVoisins( const IBestiole & ib )
{

   int         nb = 0;


   for ( std::vector<IBestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !((**it) == ib) && ib.jeTeVois(**it) )
         ++nb;

   return nb;

}

std::vector<IBestiole*>& Milieu::getListeBestiole() {return listeBestioles;};

std::vector<IBestiole*> Milieu::getBestiolesVues( IBestiole &b ) {
   std::vector<IBestiole*> listeVoisins;
   // listeVoisins.push_back(listeBestioles.at(0));
   for (IBestiole* b2 : listeBestioles) {
      if (b.getIdentite() != b2->getIdentite() && b.jeTeVois(*b2)) {
         listeVoisins.push_back(b2);
      }
   }

   return listeVoisins;
}

void Milieu::addBestiole( IBestiole* ib ) { listeBestioles.push_back(ib);listeBestioles.back()->initCoords(width, height); };

void Milieu::removeBestiole(IBestiole* ib){
   std::vector<IBestiole*>::iterator itr = std::find(listeBestioles.begin(),listeBestioles.end(),ib); 
   int idxRemove = std::distance(listeBestioles.begin(),itr); // position de la Besitole à supprimer
   listeBestioles.erase(listeBestioles.begin() + idxRemove);
   cout << "removeBestiole appelée"<<endl;
   delete ib;
}


void Milieu::naissanceSpontanee( void ){
   ConcreteCreatorBestiole creator_bestiole;
   std::random_device dev;
   std::mt19937 rng(dev());
   std::uniform_int_distribution<std::mt19937::result_type> proba_naissance(0,100);
   if (0 < proba_naissance(rng) && proba_naissance(rng) < this->getPropGreg()*100)
   {
      addBestiole(creator_bestiole.createBestiole(new ComportementGregaire()));
   }
   else if (this->getPropGreg()*100 <= proba_naissance(rng) && proba_naissance(rng) <= this->getPropPeur()*100)
   {
      addBestiole(creator_bestiole.createBestiole(new ComportementPeureuse()));
   }
   else if (this->getPropPeur()*100 <= proba_naissance(rng) && proba_naissance(rng) <= this->getPropKamik()*100)
   {
      addBestiole(creator_bestiole.createBestiole(new ComportementKamikaze()));
   }
   else if (this->getPropKamik()*100 <= proba_naissance(rng) && proba_naissance(rng) <= this->getPropPrev()*100)
   {
      addBestiole(creator_bestiole.createBestiole(new ComportementPrevoyante()));
   }
  
}


int Milieu::getWidth( void ) const { return width; };
int Milieu::getHeight( void ) const { return height; };
int Milieu::getNbBest( void ) const { return this->nb_Bestioles;};
double Milieu::getPropGreg( void ) const {return this->propGreg;};
double Milieu::getPropPeur( void ) const {return this->propPeur;};
double Milieu::getPropKamik( void ) const {return this->propKamik;};
double Milieu::getPropPrev( void ) const {return this->propPrev;};
double Milieu::getPropMult( void ) const {return this->propMult;};
ICapteur* Milieu::createCapteur(TypeCapteur type){
      return factory.createCapteur(type);
}
