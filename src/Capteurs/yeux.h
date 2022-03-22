#ifndef YEUX
#define YEUX

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Yeux : public ICapteur {
    public:
        void detection(Milieu milieu) const override;

};

#endif