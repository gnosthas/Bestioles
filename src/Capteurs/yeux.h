#ifndef YEUX
#define YEUX

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Yeux : public ICapteur {
    public:
        bool detection(Milieu milieu) const override;

};

#endif