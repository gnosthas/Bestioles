#include "Aquarium.h"
#include "Milieu.h"
// #include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   ConcreteCreatorBestiole creator_bestiole;

   for ( int i = 1; i <= 20; ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole();
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   ecosysteme.run();

      
   return 0;

}
