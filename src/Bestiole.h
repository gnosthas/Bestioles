#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "IBestiole.h"


#include <iostream>
using namespace std;


class Bestiole : public IBestiole
{

public :                                           // Forme canonique :
   Bestiole();                               // Constructeur par defaut

   Bestiole(IComportement* comportement);//fait appel au constructeur de IBestiole

   Bestiole(const Bestiole & b);//fait appel au constructeur par copie de IBestiole
   
   ~Bestiole(){cout << "Destruction bestiole" << endl;};                             // Destructeur

   Bestiole* clone() const override; //DP Prototype

   void bouge(Milieu &milieu) override;
};



#endif
