#include "IBestiole.h"
#include "Bestiole.h"



class ConcreteCreatorBestiole : public BestiolesFactory {

public:
    
    ConcreteCreatorBestiole(); //Constructeur

    *Ibestiole createBestiole(*IComportement comportement) const override;

};

#endif