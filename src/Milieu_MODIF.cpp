#include "Milieu.h"
#include "IBestiole.h"
#include "Bestiole.h"
#include "ConcreteCreatorBestiole.h"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;



const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<IBestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      (*it)->action(*this); //modif ici pour pas que erreur pointeuur pointeur **
      (*it)->draw(*this, *this); //modif ici

   } // for

}


int Milieu::nbVoisins(const IBestiole & ib)
{

   int         nb = 0;


   for ( std::vector<IBestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !((**it) == ib) && ib.jeTeVois(**it) ) //idem modif
         ++nb;

   return nb;

}
