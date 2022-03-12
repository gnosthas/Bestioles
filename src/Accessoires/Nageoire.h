#ifndef NAGEOIRE
#define NAGEOIRE

// Implémente les méthodes de l'interfacce Mob

#include "IAccessoire.h"

class Nageoire : public IAccessoire {
    private:
        double nu;

    public:
        double getMultvitesse() const;
        void setMultvitesse(double nu);
};

#endif