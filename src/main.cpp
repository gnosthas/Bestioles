#include "Aquarium.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementGregaire.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   ConcreteCreatorBestiole creator_bestiole;
   ComportementGregaire *peur = new ComportementGregaire();
   for ( int i = 1; i <= 20; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(peur);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   ecosysteme.run();
   //delete peur;


      //////////////TEST//////////////
   // Bestiole* bestiole = creator_bestiole.createBestiole(peur);
   // ecosysteme.getMilieu().addBestiole(bestiole);
  
   // IBestiole* clone_bestiole = bestiole->clone();
   // ecosysteme.getMilieu().addBestiole(clone_bestiole);

   // std::cout << clone_bestiole->get_vitesse()<<std::endl;

   // delete bestiole;
   // delete clone_bestiole;

   cout <<"fin du programme"<<endl;

   return 0;

}
