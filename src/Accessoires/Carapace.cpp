#include "Carapace.h"
// #include <iostream>
// using namespace std;

double Carapace::getResistance() const{
    // cout << "La probabilité de mort est réduite par un facteur " << this->omega << endl;
    return this->omega;   
};

double Carapace::getReducVitesse() const{
    // cout << "La réduction de vitesse est de " << this->eta << endl;
    return this->eta;   
};

Carapace::Carapace(double omega, double eta): omega(omega), eta(eta) {};