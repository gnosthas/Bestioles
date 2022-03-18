#ifndef CORPS
#define CORPS

// Implémente les méthodes de l'interfacce ICapteur

class ICapteur;

class Corps : public ICapteur {
    public:
        void detection() const override;



};

#endif