#include "Bestiole.h"
#include "BestiolesFactory.h"


class IComportement;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    Bestiole* createBestiole(IComportement* comportement) const override; //Mettre IComportement* en argument
};
