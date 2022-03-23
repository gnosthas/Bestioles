#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "IBestiole.h"
#include <iostream>
using namespace std;

class IComportement;
class Milieu;

class Bestiole : public IBestiole
{

<<<<<<< HEAD
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
=======
public :                                           // Forme canonique :
   // Bestiole(Milieu &milieu);                               // Constructeur par defaut
   Bestiole(Milieu &milieu, IComportement* comportement);//fait appel au constructeur de IBestiole
   Bestiole(const Bestiole & b);//fait appel au constructeur par copie de IBestiole
   ~Bestiole();                             // Destructeur
   IBestiole* clone() const override; //DP Prototype
>>>>>>> d59648951c8a62e82699725feb833d218f24e8cf
   void bouge() override;
};

#endif
