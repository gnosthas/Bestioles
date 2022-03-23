#ifndef _CONCRETECREATORBESTIOLE_H_
#define _CONCRETECREATORBESTIOLE_H_

#include "Bestiole.h"
#include "BestiolesFactory.h"
#include <iostream>
using namespace std;

class IComportement;
class IAccessoire;
class Milieu;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); 

    ~ConcreteCreatorBestiole(){cout << "dest Creator bestiole" << endl;}; 

    // DP Factory Method - Override de la méthode de création de Bestiole 
    Bestiole* createBestiole(Milieu& milieu, IComportement* comportement) const override; 
};

#endif