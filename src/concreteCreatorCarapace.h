#ifndef CONCRETECREATORCARAPACE
#define CONCRETECREATORCARAPACE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "accessoire.h"

class ConcreteCreatorCarapace : public AccessoiresFactory {
    public:
        Accessoire* createAccessoire() const override;
};

#endif

