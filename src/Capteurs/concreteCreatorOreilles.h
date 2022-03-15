#ifndef CONCRETECREATOROREILLES
#define CONCRETECREATOROREILLES

// Classe fille de CapteurFactory : implémente ces classes

#include "capteurFactory.h"
#include "oreilles.h"

class ConcreteCreatorOreilles : public CapteurFactory {
    public:
        Oreilles* createCapteur() const override;
};

#endif

