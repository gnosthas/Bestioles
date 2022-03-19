#include "Aquarium.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementGregaire.h"
#include "comportements/ComportementKamikaze.h"
#include "comportements/ComportementPrevoyante.h"
#include "comportements/ComportementPersMultiple.h"

#include <iostream>
#include <vector>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 120 );
   ConcreteCreatorBestiole creator_bestiole;
   IComportement *prev = new ComportementPrevoyante();
   IComportement *greg = new ComportementGregaire();
   IComportement *kami = new ComportementKamikaze();
   IComportement *peur = new ComportementPeureuse();
   std::vector<IComportement*> comportements;
   comportements.push_back(prev);
   comportements.push_back(greg);
   comportements.push_back(kami);
   comportements.push_back(peur);
   ComportementPersMultiple *pers = new ComportementPersMultiple(comportements);
   comportements.push_back(pers);
   std::cout<<"taille vect persmult : " << pers->comportements.size() << std::endl;;

   int nbPrevoyantes = 5; 
   int nbPeureuses = 5; 
   int nbGregaires = 5; 
   int nbKamikazes = 5; 
   int nbPersMult = 5; 
   for ( int i = 1; i <= nbPrevoyantes; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(prev);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= nbPeureuses; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(peur);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= nbGregaires; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(greg);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= nbKamikazes; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(kami);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= nbPersMult; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(pers);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   ecosysteme.run();

   delete peur;

   return 0;

}
