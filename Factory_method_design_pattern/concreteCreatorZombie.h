#ifndef CONCRETECREATORZOMBIE
#define CONCRETECREATORZOMBIE

// Classe fille de MobFactory : implémente ses classes
// Un appel à createMob crée un objet Zombie

#include "mobFactory.h"
#include "zombie.h"

class ConcreteCreatorZombie : public MobFactory {
    public:
        Zombie* createMob() const override;
};

#endif