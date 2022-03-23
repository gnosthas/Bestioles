#ifndef CARAPACE
#define CARAPACE

#include "IAccessoire.h"

class Carapace : public IAccessoire {
    private:
        double omega;
        double eta;

    public:
        Carapace(double omega, double eta);
        double getResistance() const;
        double getReducVitesse() const;
};

#endif