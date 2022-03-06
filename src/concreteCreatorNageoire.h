#ifndef CONCRETECREATORNAGEOIRE
#define CONCRETECREATORNAGEOIRE

// Classe fille de accessoiresFactory : implémente ces classes

#include "accessoiresFactory.h"
#include "accessoire.h"

class ConcreteCreatorNageoire : public AccessoiresFactory {
    public:
        Accessoire* createAccessoire() const override;
};

#endif

