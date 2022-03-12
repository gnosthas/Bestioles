#ifndef CONCRETECREATORCARAPACE
#define CONCRETECREATORCARAPACE

// Classe fille de accessoiresFactory : implémente ces classes

#include "AccessoiresFactory.h"
#include "Carapace.h"

class ConcreteCreatorCarapace : public AccessoiresFactory {
    public:
        Carapace* createAccessoire() const override;
};

#endif

