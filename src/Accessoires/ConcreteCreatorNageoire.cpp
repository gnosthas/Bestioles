#include "iostream"
#include "concreteCreatorNageoire.h"
using namespace std;


Nageoire* ConcreteCreatorNageoire::createAccessoire() const{
            cout << "Création d'une nageoire" << endl;
            return new Nageoire();
};

