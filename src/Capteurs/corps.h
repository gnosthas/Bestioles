#ifndef CORPS
#define CORPS

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Corps : public ICapteur {
    public:
        void detection() const override;



};

#endif