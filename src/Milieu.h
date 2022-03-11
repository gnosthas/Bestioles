#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };
   std::vector<Bestiole>& getListeBestioles(void) {return listeBestioles;};
   void step( void );

   void ajouterBestiole( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); };
   int nbVoisins( const Bestiole & b );
   std::vector<Bestiole>& getBestiolesVues(const Bestiole& b);
};


#endif
