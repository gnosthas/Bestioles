#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Capteurs/concreteCreatorYeux.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 1920 , 1080, 30 );

    for ( int i = 1; i <= 10; ++i ){
       ecosysteme.getMilieu().addMember( Bestiole() );
   }


   ConcreteCreatorYeux eyez;
   Yeux* test_eyez = eyez.createCapteur();
   test_eyez->detection();

   ecosysteme.run();
   delete test_eyez;


   return 0;

}
