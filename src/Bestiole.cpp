#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/IComportement.h"

using namespace std;

//Constructeur
Bestiole::Bestiole(Milieu &milieu, IComportement* comportement):IBestiole(milieu, comportement){}

//Constructeur par copie
Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}

//Destructeur
Bestiole::~Bestiole(){}

//DP Prototype - override de la méthode clone() issue de IBestiole - fait appel au constructeur de Bestiole
IBestiole* Bestiole::clone() const{
   cout << "Je suis issu d'un clonage" << endl;
    return new Bestiole(*this);
}

//DP Visitor - Méthode bouge qui fait appel à bougeselonComportement
void Bestiole::bouge(){
   comportement->bougeSelonComportement(this->milieu, *this);
}
