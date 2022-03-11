#ifndef CONCRETECREATORCOCHON
#define CONCRETECREATORCOCHON

// Classe fille de MobFactory : implémente ces classes
// Un appel à createMob crée un objet Cochon

#include "mobFactory.h"
#include "cochon.h"

class ConcreteCreatorCochon : public MobFactory {
    public:
        Cochon* createMob() const override;
};

#endif

