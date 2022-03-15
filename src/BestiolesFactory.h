#include "IBestiole.h"
#include "comportements/IComportement.h"


class IComportement;

class BestiolesFactory{

public:

    virtual ~BestiolesFactory();
    virtual IBestiole* createBestiole(IComportement* comportement) const = 0; //Mettre IComportement* en argument

};
