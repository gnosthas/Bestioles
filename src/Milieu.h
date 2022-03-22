#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Capteurs/capteurFactory.h"
#include <iostream>
#include <vector>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   
   std::vector<IBestiole*>   listeBestioles;

   CapteurFactory            factory;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };
   std::vector<IBestiole*>& getListeBestiole() {return listeBestioles;};
   void step( void );

   // void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   void addBestiole( IBestiole* ib ) { listeBestioles.push_back(ib);listeBestioles.back()->initCoords(width, height); };
   int nbVoisins( const IBestiole & ib );


};


#endif
