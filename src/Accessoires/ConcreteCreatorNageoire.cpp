#include "iostream"
#include "ConcreteCreatorNageoire.h"
using namespace std;


Nageoire* ConcreteCreatorNageoire::createAccessoire() const{
            cout << "Création d'une nageoire" << endl;
            return new Nageoire();
};

