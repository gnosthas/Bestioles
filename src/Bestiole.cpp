#include <iostream>
#include "Bestiole.h"

using namespace std;

// Bestiole::Bestiole(IComportement* comportement):IBestiole(comportement){}
Bestiole::Bestiole():IBestiole(){
   cout << "Création nouvelle bestiole" << endl;
}
Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}

Bestiole* Bestiole::clone() const{
    return new Bestiole(*this);
}