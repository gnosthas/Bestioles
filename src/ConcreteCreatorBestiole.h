#ifndef _CONCRETECREATORBESTIOLE_H_
#define _CONCRETECREATORBESTIOLE_H_

#include "Bestiole.h"
#include "BestiolesFactory.h"
// #include "comportements/IComportement.h"
#include <iostream>
using namespace std;

class IComportement;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    ~ConcreteCreatorBestiole(){cout << "Destruction concrete creator bestiole" << endl;}; //Destructeur

    Bestiole* createBestiole(IComportement* comportement) const override; //Mettre IComportement* en argument
    Bestiole* createBestiole() const override; ////////// TEMPORAIRE POUR TEST COMPILATION
};

#endif