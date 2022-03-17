#include "ConcreteCreatorBestiole.h"
#include "comportements/IComportement.h"

using namespace std;



//Constructeur
ConcreteCreatorBestiole::ConcreteCreatorBestiole() : BestiolesFactory(){}


//On fait le choix de renvoyer un pointeur de Bestiole plutôt qu'un pointeur de IBestiole pour des 
//raisons de clarté (& utilisation du type covariant)
IBestiole* ConcreteCreatorBestiole::createBestiole(IComportement* comportement) const {

        IBestiole* bestiole = new Bestiole(comportement);
        
        //Random ajout d'accessoires et de capteurs i.e appel aux fabriques de capteurs et d'accessoires
        // Associé yeux/oreilles/nageoires/camouflage/carapace...

        return bestiole;
}

