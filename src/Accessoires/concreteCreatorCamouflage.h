#ifndef CONCRETECREATORCAMOUFLAGE
#define CONCRETECREATORCAMOUFLAGE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "camouflage.h"

class ConcreteCreatorCamouflage : public AccessoiresFactory {
    public:
        Camouflage* createAccessoire() const override;
};

#endif

