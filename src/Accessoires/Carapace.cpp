#include "Carapace.h"
#include <iostream>
using namespace std;

double Carapace::getResistance() const{
    cout << "La probabilité de mort est réduite par un facteur " << this->omega << endl;
    return this->omega;   
};

void Carapace::setResistance(double omega){
    cout << "Mise à jour de la probabilité de mort grâce à la carapace" << this->omega << endl;
    this->omega = omega; 
};

double Carapace::getReducVitesse() const{
    cout << "La réduction de vitesse est de " << this->eta << endl;
    return this->eta;   
};

void Carapace::setReducVitesse(double eta){
    cout << "Mise à jour de la réduction de la vitesse" << this->eta << endl;
    this->eta = eta; 
};