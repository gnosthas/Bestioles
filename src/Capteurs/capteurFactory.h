#ifndef CAPTEURFACTORY
#define CAPTEURFACTORY

#include <iostream>

class ICapteur;

enum TypeCapteur{
    TC_Yeux, TC_Oreilles, TC_Corps
};

class CapteurFactory {
    public:
        ~CapteurFactory(){std::cout<<"Destruction capteur factory"<<std::endl;};
        static ICapteur* createCapteur(TypeCapteur type);
};
#endif