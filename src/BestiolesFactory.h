#ifndef _BESTIOLESFACTORY_H_
#define _BESTIOLESFACTORY_H_

#include "IBestiole.h"
// #include "comportements/IComportement.h"

#include <iostream>
using namespace std;

////////// TEMPORAIRE POUR TEST COMPILATION
class IComportement;
class Mileu;

class BestiolesFactory{

public:

    virtual ~BestiolesFactory(void){};
    // BestiolesFactory(void);
    
    ////////// TEMPORAIRE POUR TEST COMPILATION
    virtual IBestiole* createBestiole(Milieu& milieu, IComportement* comportement) const = 0; //Mettre IComportement* en argument
    virtual IBestiole* createBestiole(Milieu& milieu) const = 0;

};

#endif