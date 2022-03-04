#ifndef CONCRETECREATORCOCHON
#define CONCRETECREATORCOCHON

// Classe fille de MobFactory : implémente ces classes
// Un appel à createMob crée un objet Cochon

#include "mobFactory.h"
#include "mob.h"

class ConcreteCreatorCochon : public MobFactory {
    public:
        Mob* createMob() const override;
};

#endif

