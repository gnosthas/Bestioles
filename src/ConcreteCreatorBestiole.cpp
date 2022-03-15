#include "ConcreteCreatorBestiole.h"
#include "comportements/IComportement.h"

using namespace std;

Bestiole* ConcreteCreatorBestiole::createBestiole(IComportement* comportement) const {

        //Bestiole* bestiole = new Bestiole(comportement);

        //Random ajout d'accessoires et de capteurs i.e appel aux fabriques de capteurs et d'accessoires
        return new Bestiole(comportement);
}

