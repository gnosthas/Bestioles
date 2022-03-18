#ifndef CAPTEURFACTORY
#define CAPTEURFACTORY

#include "capteur.h"

enum TypeCapteur{
    TC_Yeux, TC_Oreilles, TC_Corps
};

class CapteurFactory {
    public:
        ~CapteurFactory(){};
        ICapteur* createCapteur(TypeCapteur type, int id);
};


#endif