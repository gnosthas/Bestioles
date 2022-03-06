#include "iostream"
#include "concreteCreatorCarapace.h"
#include "carapace.h"
using namespace std;


Accessoire* ConcreteCreatorCarapace::createAccessoire() const{
            cout << "Création d'une carapace" << endl;
            return new Carapace();
};

