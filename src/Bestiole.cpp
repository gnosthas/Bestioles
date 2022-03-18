#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "IBestiole.h"

using namespace std;

Bestiole::Bestiole(IComportement* comportement):IBestiole(comportement){}
Bestiole::Bestiole():IBestiole(){
   cout << "Création nouvelle bestiole" << endl;
}
Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}

Bestiole::~Bestiole(){cout << "Destruction bestiole" << endl;}

Bestiole* Bestiole::clone() const{
    return new Bestiole(*this);
}

void Bestiole::bouge(Milieu &milieu){
   std::vector<IBestiole*> listeVoisins = milieu.getBestiolesVues(*this);
   comportement->bougeSelonComportement(milieu, *this);
}
