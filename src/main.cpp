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

   // Camouflage* camouflage = creator_camouflage.createAccessoire();
   // Carapace* carapace = creator_carapace.createAccessoire();
   // Nageoire* nageoire = creator_nageoire.createAccessoire();

   // camouflage->getCamouflage();
   // camouflage->setCamouflage(0.3);
   // camouflage->getCamouflage();

   // carapace->setResistance(5.);
   // carapace->setReducVitesse(0.5);
   // carapace->getResistance();
   // carapace->getReducVitesse();

   // nageoire->setMultvitesse(3);
   // nageoire->getMultvitesse();

   // delete camouflage;
   // delete carapace;
   // delete nageoire;

   return 0;

}
