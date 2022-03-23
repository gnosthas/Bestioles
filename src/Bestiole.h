#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "IBestiole.h"
#include <iostream>
using namespace std;

class IComportement;
class Milieu;

class Bestiole : public IBestiole
{

public :          
   // Constructeur non utilisé en pratique                                
   Bestiole(Milieu &milieu);  

   // Constructeur
   Bestiole(Milieu &milieu, IComportement* comportement);

   // Constructeur par copie
   Bestiole(const Bestiole & b);
   
   // Destructeur
   ~Bestiole();                             

   //DP Prototype - override de la méthode clone() issue de IBestiole
   IBestiole* clone() const override; 

   //override de la méthode bouge() issue de IBestiole
   void bouge() override;
};



#endif
