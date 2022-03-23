#ifndef _CONCRETECREATORBESTIOLE_H_
#define _CONCRETECREATORBESTIOLE_H_

#include "Bestiole.h"
#include "BestiolesFactory.h"
// #include "comportements/IComportement.h"
#include <iostream>
using namespace std;

class IComportement;
class IAccessoire;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    ~ConcreteCreatorBestiole(){cout << "dest Creator bestiole" << endl;}; //Destructeur

    Bestiole* createBestiole(IComportement* comportement) const override; 
    Bestiole* createBestiole() const override;
};

#endif