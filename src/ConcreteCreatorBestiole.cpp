#include "ConcreteCreatorBestiole.h"

#include <iostream>
using namespace std;



ConcreteCreatorBestiole::ConcreteCreatorBestiole() : BestiolesFactory(){cout << "const creator bestiole" << endl;}


Bestiole* ConcreteCreatorBestiole::createBestiole(Milieu& milieu, IComportement* comportement) const {

        Bestiole* bestiole = new Bestiole(milieu, comportement);

        return bestiole;
}


