#ifndef CONCRETECREATORNAGEOIRE
#define CONCRETECREATORNAGEOIRE

// Classe fille de accessoiresFactory : implémente ces classes

#include "AccessoiresFactory.h"
#include "Nageoire.h"

class ConcreteCreatorNageoire : public AccessoiresFactory {
    public:
        Nageoire* createAccessoire() const override;
};

#endif