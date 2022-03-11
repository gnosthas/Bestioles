#ifndef CONCRETECREATORCARAPACE
#define CONCRETECREATORCARAPACE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "carapace.h"

class ConcreteCreatorCarapace : public AccessoiresFactory {
    public:
        Carapace* createAccessoire() const override;
};

#endif

