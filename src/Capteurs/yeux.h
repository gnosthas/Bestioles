#ifndef YEUX.H
#define YEUX.H

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"


class Yeux : public ICapteur {
    public:
        void detection() const override;

};

#endif