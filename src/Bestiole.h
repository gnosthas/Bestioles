#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include "IBestiole.h"

#include <iostream>

using namespace std;

class Bestiole : public IBestiole
{

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut

   Bestiole(IComportement* comportement);//fait appel au constructeur de IBestiole

   Bestiole(const Bestiole & b);//fait appel au constructeur par copie de IBestiole
   
   ~Bestiole(void){};                             // Destructeur ABSOLUTELY HAVE A BODY BECAUSE IT HERITS FROM A VIRTUAL DESTRUCTOR

   IBestiole* clone() const override; //DP Prototype
};


#endif
