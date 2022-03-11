#ifndef CARAPACE
#define CARAPACE

// Implémente les méthodes de l'interfacce Mob

#include "iaccessoire.h"

class Carapace : public IAccessoire {
    private:
        double omega;
        double eta;

    // public:
    //     void noise() const override;

};

#endif