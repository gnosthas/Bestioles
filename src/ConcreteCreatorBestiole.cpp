#include "ConcreteCreatorBestiole.h"

#include <iostream>
using namespace std;



//Constructeur
ConcreteCreatorBestiole::ConcreteCreatorBestiole() : BestiolesFactory(){cout << "const creator bestiole" << endl;}


//On fait le choix de renvoyer un pointeur de Bestiole plutôt qu'un pointeur de IBestiole pour des 
//raisons de clarté (& utilisation du type covariant)
Bestiole* ConcreteCreatorBestiole::createBestiole(IComportement* comportement) const {

        Bestiole* bestiole = new Bestiole(comportement);
        
        //Random ajout d'accessoires et de capteurs i.e appel aux fabriques de capteurs et d'accessoires
        // Associé yeux/oreilles/nageoires/camouflage/carapace...

        return bestiole;
}

////////// TEMPORAIRE POUR TEST COMPILATION
Bestiole* ConcreteCreatorBestiole::createBestiole() const {
        Bestiole* bestiole = new Bestiole();
        return bestiole;
}

