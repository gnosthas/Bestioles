#ifndef OREILLES
#define OREILLES

// Implémente les méthodes de l'interfacce ICapteur

#include "capteur.h"

class Oreilles : public ICapteur {
    private:
        double alpha_m;
        double alpha_M;
        double delta_m;
        double delta_M;
        double gamma_m;
        double gamma_M ;
        float posX;
        float posY;




    public:

        void detection() const override;



};

#endif