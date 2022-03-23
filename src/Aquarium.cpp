#include "Aquarium.h"

#include "Milieu.h"
#include "IBestiole.h"


Aquarium::Aquarium( int width, int height, int _delay, int nb_Bestioles, double Greg, double Peur, double Kamik, double Prev, double Mult ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height, nb_Bestioles, Greg, Peur, Kamik, Prev, Mult );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}

Milieu& Aquarium::getMilieu( void ) { return *flotte; }

void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;
   bool pause = false;

   // flotte->initialisation();

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;
      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
         if ( is_keySPACE() ) pause = !pause;
      }
      if (!pause) {
         cout << "------------ Nouveau pas : il y a " << flotte->getListeBestiole().size() << " bestioles dans l'aquarium ------------"<< endl;
         flotte->step();

         display( *flotte );

         
      }
      

      wait( delay );

   }
}
