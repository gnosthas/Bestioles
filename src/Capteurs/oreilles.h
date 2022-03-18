#ifndef OREILLES
#define OREILLES

// Implémente les méthodes de l'interfacce ICapteur

class ICapteur;

class Oreilles : public ICapteur {
    public:

        void detection() const override;



};

#endif