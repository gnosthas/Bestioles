#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"

#include <iostream>

using namespace std;


class Milieu;


class Bestiole : public IBestiole
{

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut

   Bestiole(*Icomportement comportement);

   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur

   


   Bestiole(*IComportement comportement) : comportement(comportement){};

   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   *IBestiole clone();

   
} 

};


#endif
