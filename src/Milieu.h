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
   std::vector<IBestiole*>   listeBestioles; //on fait le choix de stocker des pointeurs de IBestiole vers des bestioles

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };
   std::vector<IBestiole*>& getListeBestioles(void) {return listeBestioles;};
   void step( void );

   
   void addBestiole(IBestiole* ib) {listeBestioles.push_back(ib);listeBestioles.back()->initCoords(width, height); };
   void removeBestiole (IBestiole* ib);

   int nbVoisins( const IBestiole & ib );
   
   // std::vector<Bestiole>& getBestiolesVues(const Bestiole& b);
};


#endif
