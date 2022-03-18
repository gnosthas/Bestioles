#include "Nageoire.h"
#include <iostream>
using namespace std;

double Nageoire::getMultvitesse() const{
    cout << "Le multiplicateur de vitesse est à la valeur : " << this->nu << endl;
    return this->nu;   
};

void Nageoire::setMultvitesse(double nu){
    cout << "Mise à jour du mulitplicateur de vitesse lié aux nageoires" << endl;
    this->nu = nu; 
};