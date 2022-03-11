#ifndef CONCRETECREATORYEUX
#define CONCRETECREATORYEUX

// Classe fille de CapteurFactory : implémente ces classes

#include "capteurFactory.h"
#include "yeux.h"

class ConcreteCreatorYeux : public CapteurFactory {
    public:
        Yeux* createCapteur() const override;
};

#endif

