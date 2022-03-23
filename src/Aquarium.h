#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay, int nb_Bestioles, double Greg, double Peur, double Kamik, double Prev, double Mult );
   ~Aquarium( void );

   Milieu & getMilieu( void );

   void run( void );

};


#endif
