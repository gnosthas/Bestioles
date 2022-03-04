#ifndef ZOMBIE
#define ZOMBIE

// Implémente les méthodes de l'interfacce Mob

#include "mob.h"

class Zombie : public Mob {
    private:
        int nb_coeurs;
        bool IsAlive;
        int pt_attack;
    
    public:
        void noise() const override;
};

#endif
