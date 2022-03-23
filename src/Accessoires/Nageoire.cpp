#include "Nageoire.h"

double Nageoire::getMultvitesse() const{
    // cout << "Le multiplicateur de vitesse est à la valeur : " << this->nu << endl;
    return this->nu;   
};

Nageoire::Nageoire(double nu): nu(nu) {};

