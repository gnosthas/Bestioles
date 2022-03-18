#include "Camouflage.h"
#include <iostream>
using namespace std;

double Camouflage::getCamouflage() const{
    cout << "Camouflage est à la valeur : " << this->psi << endl;
    return this->psi;   
};

void Camouflage::setCamouflage(double psi){
    cout << "Mise à jour de la valeur de camouflage" << endl;
    this->psi = psi; 
};