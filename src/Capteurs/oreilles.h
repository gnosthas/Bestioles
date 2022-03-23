#ifndef OREILLES
#define OREILLES

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Oreilles : public ICapteur {
    public:

        bool detection(Milieu milieu) const override;



};

#endif