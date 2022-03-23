#ifndef CONCRETECREATORCARAPACE
#define CONCRETECREATORCARAPACE

// Classe fille de accessoiresFactory : implémente cette classe

#include "AccessoiresFactory.h"
#include "Carapace.h"

class ConcreteCreatorCarapace : public AccessoiresFactory {
    public:
        Carapace* createAccessoire() const override;
};

#endif

