#include "Camouflage.h"
// #include <iostream>
// using namespace std;

double Camouflage::getCamouflage() const{
    // cout << "Camouflage est à la valeur : " << this->psi << endl;
    return this->psi;   
};

Camouflage::Camouflage(double psi): psi(psi) {};