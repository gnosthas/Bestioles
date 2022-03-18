#ifndef YEUX
#define YEUX

// Implémente les méthodes de l'interfacce ICapteur

class ICapteur;

class Yeux : public ICapteur {
    public:
        void detection() const override;

};

#endif