#ifndef CONCRETECREATORNAGEOIRE
#define CONCRETECREATORNAGEOIRE

// Classe fille de accessoiresFactory : implémente cette classe

#include "AccessoiresFactory.h"
#include "Nageoire.h"

class ConcreteCreatorNageoire : public AccessoiresFactory {
    public:
        Nageoire* createAccessoire() override;
};

#endif