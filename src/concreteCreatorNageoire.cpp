#include "iostream"
#include "concreteCreatorNageoire.h"
#include "nageoire.h"
using namespace std;


Accessoire* ConcreteCreatorNageoire::createAccessoire() const{
            cout << "Création d'une nageoire" << endl;
            return new Nageoire();
};

