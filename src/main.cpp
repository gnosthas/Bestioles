#include "Aquarium.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementPeureuse.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   ConcreteCreatorBestiole creator_bestiole;
   ComportementPeureuse *peur = new ComportementPeureuse();
   for ( int i = 1; i <= 20; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(peur);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   ecosysteme.run();

      
   return 0;

}
