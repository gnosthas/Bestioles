#include "Bestiole.h"
#include "BestiolesFactory.h"


class IComportement;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    IBestiole* createBestiole(IComportement* comportement) const override; 
};
