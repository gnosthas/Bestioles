#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/IComportement.h"

using namespace std;

<<<<<<< HEAD
//////////////////////////// Constructeur Bestiole //////////////////////////////////////////
Bestiole::Bestiole(IComportement* comportement):IBestiole(comportement){}

Bestiole::Bestiole():IBestiole()
{
=======
Bestiole::Bestiole(Milieu &milieu, IComportement* comportement):IBestiole(milieu, comportement){}
Bestiole::Bestiole(Milieu &milieu):IBestiole(milieu){
>>>>>>> 62620cada6977ab5a76b5f29e314af304daf23bf
   cout << "Création nouvelle bestiole" << endl;
}
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
