#ifndef CONCRETECREATORCAMOUFLAGE
#define CONCRETECREATORCAMOUFLAGE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "accessoire.h"

class ConcreteCreatorCamouflage : public AccessoiresFactory {
    public:
        Accessoire* createAccessoire() const override;
};

#endif

