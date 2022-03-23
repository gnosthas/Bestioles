#include "iostream"
#include "ConcreteCreatorCamouflage.h"

Camouflage* ConcreteCreatorCamouflage::createAccessoire() const{
            double PSI_MAX = 2;
            double psi;
            psi =  ((double) rand() / (RAND_MAX))*(PSI_MAX-1) + 1; // Génération d'un nombre aléatoire entre [1;PSI_MAX]
            std::cout << "const Camouflage - coef " << psi << std::endl;
            return new Camouflage(psi);
};

