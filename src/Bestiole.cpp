#include <iostream>
#include <vector>
#include "Bestiole.h"
#include "Milieu.h"
#include "comportements/IComportement.h"

using namespace std;

//Constructeur
Bestiole::Bestiole(Milieu &milieu, IComportement* comportement):IBestiole(milieu, comportement){}
<<<<<<< HEAD

//Constructeur par copie
=======
>>>>>>> d59648951c8a62e82699725feb833d218f24e8cf
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
