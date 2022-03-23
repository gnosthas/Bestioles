#ifndef CONCRETECREATORCAMOUFLAGE
#define CONCRETECREATORCAMOUFLAGE

// Classe fille de accessoiresFactory : implémente cette classe

#include "AccessoiresFactory.h"
#include "Camouflage.h"

class ConcreteCreatorCamouflage : public AccessoiresFactory {
    public:
        Camouflage* createAccessoire() override;
};

#endif

