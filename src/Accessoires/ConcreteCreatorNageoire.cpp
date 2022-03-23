#include "iostream"
#include "ConcreteCreatorNageoire.h"
using namespace std;


Nageoire* ConcreteCreatorNageoire::createAccessoire() {
            double nu;
            nu =  ((double) rand() / (RAND_MAX))*(NU_MAX-1) + 1; // Génération d'un nombre aléatoire entre [1;NU_MAX]
            cout << "const Nageoire - coef " << nu << endl;
            return new Nageoire(nu);
};

