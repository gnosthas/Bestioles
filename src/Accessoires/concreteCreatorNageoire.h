#ifndef CONCRETECREATORNAGEOIRE
#define CONCRETECREATORNAGEOIRE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "nageoire.h"

class ConcreteCreatorNageoire : public AccessoiresFactory {
    public:
        Nageoire* createAccessoire() const override;
};

#endif

