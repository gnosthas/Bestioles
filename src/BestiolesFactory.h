#ifndef _BESTIOLESFACTORY_H_
#define _BESTIOLESFACTORY_H_

#include "IBestiole.h"
#include <iostream>
using namespace std;

class IComportement;
class Mileu;

class BestiolesFactory{

public:
    virtual ~BestiolesFactory(void){};
    
    //DP Factory Method - méthode virtuelle pure
    virtual IBestiole* createBestiole(Milieu& milieu, IComportement* comportement) const = 0;


};

#endif