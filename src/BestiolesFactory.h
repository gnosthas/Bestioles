#ifndef _BESTIOLESFACTORY_H_
#define _BESTIOLESFACTORY_H_

#include "IBestiole.h"
// #include "comportements/IComportement.h"

#include <iostream>
using namespace std;

////////// TEMPORAIRE POUR TEST COMPILATION
// class IComportement;

class BestiolesFactory{

public:

    virtual ~BestiolesFactory(void){};
    // BestiolesFactory(void);
    
    ////////// TEMPORAIRE POUR TEST COMPILATION
    // virtual IBestiole* createBestiole(IComportement* comportement) const = 0; //Mettre IComportement* en argument
    virtual IBestiole* createBestiole() const = 0;

};

#endif