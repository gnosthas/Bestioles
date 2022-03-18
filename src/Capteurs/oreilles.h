#ifndef OREILLES.H
#define OREILLES.H

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Oreilles : public ICapteur {
    public:

        void detection() const override;



};

#endif