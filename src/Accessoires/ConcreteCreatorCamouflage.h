#ifndef CONCRETECREATORCAMOUFLAGE
#define CONCRETECREATORCAMOUFLAGE

// Classe fille de accessoiresFactory : implémente ces classes

#include "AccessoiresFactory.h"
#include "Camouflage.h"

class ConcreteCreatorCamouflage : public AccessoiresFactory {
    public:
        Camouflage* createAccessoire() const override;
};

#endif

