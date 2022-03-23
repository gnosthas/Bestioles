#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/IComportement.h"

using namespace std;

Bestiole::Bestiole(Milieu &milieu, IComportement* comportement):IBestiole(milieu, comportement){}
Bestiole::Bestiole(Milieu &milieu):IBestiole(milieu){
   cout << "Création nouvelle bestiole" << endl;
}
Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}

Bestiole::~Bestiole(){}//cout << "Destruction bestiole" << endl;}

IBestiole* Bestiole::clone() const{
   cout << "Je suis issu d'un clonage" << endl;
    return new Bestiole(*this);
    
}

void Bestiole::bouge(){
   comportement->bougeSelonComportement(this->milieu, *this);
}
