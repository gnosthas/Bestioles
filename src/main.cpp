#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Accessoires/concreteCreatorCamouflage.h"
#include "Accessoires/concreteCreatorCarapace.h"
#include "Accessoires/concreteCreatorNageoire.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();

   // ConcreteCreatorCamouflage creator_camouflage;
   // ConcreteCreatorCarapace creator_carapace;
   // ConcreteCreatorNageoire creator_nageoire;

   // Camouflage* test_camouflage = creator_camouflage.createAccessoire();
   // Carapace* test_carapace = creator_carapace.createAccessoire();
   // Nageoire* test_nageoire = creator_nageoire.createAccessoire();

   // delete test_camouflage;
   // delete test_carapace;
   // delete test_nageoire;

   return 0;

}
