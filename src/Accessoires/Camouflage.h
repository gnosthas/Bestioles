#ifndef CAMOUFLAGE
#define CAMOUFLAGE

// Implémente les méthodes de l'interfacce Mob

#include "IAccessoire.h"

class Camouflage : public IAccessoire {
    private:
        double psi;
    public:
        double getCamouflage() const;
        void setCamouflage(double psi);
};

#endif