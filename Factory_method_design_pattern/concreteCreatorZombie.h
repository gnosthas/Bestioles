#ifndef CONCRETECREATORZOMBIE
#define CONCRETECREATORZOMBIE

// Classe fille de MobFactory : implémente ses classes
// Un appel à createMob crée un objet Zombie

#include "mobFactory.h"
#include "mob.h"

class ConcreteCreatorZombie : public MobFactory {
    public:
        Mob* createMob() const override;
};

#endif