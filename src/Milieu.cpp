#include "Milieu.h"
#include "IBestiole.h"

#include <cstdlib>
#include <ctime>

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

      (*it)->action( *this );

      (*it)->draw( *this );

   } // for

}


int Milieu::nbVoisins( const IBestiole & ib )
{

   int         nb = 0;


   for ( std::vector<IBestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !((**it) == ib) && ib.jeTeVois(**it) )
         ++nb;

   return nb;

}

std::vector<IBestiole*>& Milieu::getListeBestiole() {return listeBestioles;};

std::vector<IBestiole*> Milieu::getBestiolesVues( IBestiole &b ) {
   std::vector<IBestiole*> listeVoisins;
   listeVoisins.push_back(listeBestioles.at(0));

   return listeVoisins;
}

void Milieu::addBestiole( IBestiole* ib ) { listeBestioles.push_back(ib);listeBestioles.back()->initCoords(width, height); };

int Milieu::getWidth( void ) const { return width; };
int Milieu::getHeight( void ) const { return height; };