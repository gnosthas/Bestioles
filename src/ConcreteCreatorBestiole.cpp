#include "ConcrecteCreatorBestiole.h"

using namespace std;

class ConcreteCreatorBestiole{


IBestiole* ConcreteCreatorBestiole::createBestiole(IComportement* comportement){

        *IBestiole bestiole = new Bestiole(comportement);

        //Random ajout d'accessoires et de capteurs i.e appel aux fabriques de capteurs et d'accessoires

        return bestiole
}

};

#endif