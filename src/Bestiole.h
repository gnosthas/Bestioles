#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "IBestiole.h"


#include <iostream>
using namespace std;

class IComportement;
class Milieu;

class Bestiole : public IBestiole
{

public :                                           // Forme canonique :
   // Bestiole(Milieu &milieu);                               // Constructeur par defaut
   Bestiole(Milieu &milieu, IComportement* comportement);//fait appel au constructeur de IBestiole
   Bestiole(const Bestiole & b);//fait appel au constructeur par copie de IBestiole
   ~Bestiole();                             // Destructeur
   IBestiole* clone() const override; //DP Prototype
   void bouge() override;
};

#endif
