#ifndef COCHON
#define COCHON

// Implémente les méthodes de l'interfacce Mob

#include "mob.h"


class Cochon : public Mob {
    private:
        int nb_coeurs;
        bool IsAlive;
        int pt_attack;

    public:
        void noise() const override;

};

#endif