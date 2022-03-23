#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/IComportement.h"

using namespace std;

Bestiole::Bestiole(Milieu &milieu, IComportement* comportement):IBestiole(milieu, comportement){}
Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}

Bestiole::~Bestiole(){}

// Implémentation du DP Prototype par override //
IBestiole* Bestiole::clone() const{
   cout << "Je suis issu d'un clonage" << endl;
    return new Bestiole(*this);
}

void Bestiole::bouge(){
   comportement->bougeSelonComportement(this->milieu, *this);
}
