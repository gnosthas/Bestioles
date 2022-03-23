#ifndef CORPS
#define CORPS

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Milieu;

class Corps : public ICapteur {
    public:
        bool detection(Milieu milieu) const override;


};

#endif