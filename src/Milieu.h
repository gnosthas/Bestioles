#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;

class IBestiole;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   
   std::vector<IBestiole*>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const;
   int getHeight( void ) const;
   std::vector<IBestiole*>& getListeBestiole();
   void step( void );

   void addBestiole( IBestiole* ib );
   int nbVoisins( const IBestiole & ib );

   std::vector<IBestiole*> getBestiolesVues( IBestiole &b );
};


#endif
