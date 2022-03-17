#ifndef YEUX
#define YEUX

// Implémente les méthodes de l'interfacce Capteur

#include "capteur.h"

class Yeux : public ICapteur {
    private:
        double alpha;

    public:
        void detection() const override;

};

#endif