#ifndef CORPS
#define CORPS

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Milieu;

class Corps : public ICapteur {
    public:
        void detection(Milieu milieu) const override;



};

#endif