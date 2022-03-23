#ifndef CAMOUFLAGE
#define CAMOUFLAGE

// Implémente les méthodes de l'interfacce Mob

#include "IAccessoire.h"

class Camouflage : public IAccessoire {
    private:
        double psi;
    public:
        Camouflage(double psi);
        double getCamouflage() const;
};

#endif