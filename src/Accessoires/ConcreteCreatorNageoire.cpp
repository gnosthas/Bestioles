#include "iostream"
#include "ConcreteCreatorNageoire.h"
using namespace std;


Nageoire* ConcreteCreatorNageoire::createAccessoire() const{
            double NU_MAX = 2;
            double nu;
            nu = ((double) rand() / (RAND_MAX))*(NU_MAX-1) + 1;
            cout << "Création d'une nageoire de coefficient " << nu << endl;
            return new Nageoire(nu);
};

