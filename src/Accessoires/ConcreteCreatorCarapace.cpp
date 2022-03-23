#include "iostream"
#include "ConcreteCreatorCarapace.h"
using namespace std;


Carapace* ConcreteCreatorCarapace::createAccessoire() const{
            double OMEGA_MAX = 2;
            double ETA_MAX = 2;
            double omega;
            double eta;
            omega =  ((double) rand() / (RAND_MAX))*(OMEGA_MAX-1) + 1; // Génération d'un nombre aléatoire entre [1;OMEGA_MAX]
            eta =  ((double) rand() / (RAND_MAX))*(ETA_MAX-1) + 1; // Génération d'un nombre aléatoire entre [1;ETA_MAX]
            cout << "const Carapace - protection : " << omega << " - lenteur : " << eta << endl;
            return new Carapace(omega, eta);
};