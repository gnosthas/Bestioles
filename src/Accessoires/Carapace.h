#ifndef CARAPACE
#define CARAPACE

// Implémente les méthodes de l'interfacce Mob

#include "IAccessoire.h"

class Carapace : public IAccessoire {
    private:
        double omega;
        double eta;

    public:
        double getResistance() const;
        void setResistance(double omega);
        double getReducVitesse() const;
        void setReducVitesse(double eta);
};

#endif