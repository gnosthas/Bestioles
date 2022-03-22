#ifndef OREILLES
#define OREILLES

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Oreilles : public ICapteur {
    public:

        void detection(Milieu milieu) const override;



};

#endif