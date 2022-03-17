#include "Bestiole.h"
#include "BestiolesFactory.h"
// #include "comportements/IComportement.h"


class IComportement;

class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    // Bestiole* createBestiole(IComportement* comportement) const override; //Mettre IComportement* en argument
    Bestiole* createBestiole() const override; ////////// TEMPORAIRE POUR TEST COMPILATION
};
