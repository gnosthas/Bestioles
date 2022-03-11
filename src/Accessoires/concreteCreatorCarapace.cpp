#include "iostream"
#include "concreteCreatorCarapace.h"
using namespace std;


Carapace* ConcreteCreatorCarapace::createAccessoire() const{
            cout << "Création d'une carapace" << endl;
            return new Carapace();
};

