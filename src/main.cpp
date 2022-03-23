#include "Aquarium.h"
#include "Milieu.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementGregaire.h"
#include "comportements/ComportementKamikaze.h"
#include "comportements/ComportementPrevoyante.h"
#include "comportements/ComportementPersMultiple.h"
#include "Accessoires/ConcreteCreatorNageoire.h"
#include "Accessoires/ConcreteCreatorCarapace.h"

#include <iostream>
#include <vector>


using namespace std;


int main()
{

/////////////////////// CREATION DES COMPORTEMENTS INITIAUX /////////////////////////////
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


   ///////////////////////// CREATION DE LA CONFIGURATION DE LA POPULATION INITIALE//////////////////
   //Nombre Bestioles = 30
   //Proportion gregaire = kamikaze = peureuse = prevoyante = personnalités mult = 0.20
   Aquarium       ecosysteme( 640, 480, 60,  30, 0.20, 0.20, 0.20, 0.20, 0.20);

   ConcreteCreatorBestiole creator_bestiole;

   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropGreg()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),greg);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPeur()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),peur);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropKamik()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),kami);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPrev()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),prev);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropMult()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),pers);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   ecosysteme.run();

   delete prev;
   delete greg;
   delete kami;
   delete peur;
   delete pers;


   return 0;

}
