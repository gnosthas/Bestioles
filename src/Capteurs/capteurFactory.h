
#ifndef CAPTEURFACTORY
#define CAPTEURFACTORY

#include <iostream>
using namespace std;

class ICapteur;

enum TypeCapteur{
    TC_Yeux, TC_Oreilles, TC_Corps
};

class CapteurFactory {
    public:
        ~CapteurFactory(){cout<<"Destruction capteur factory"<<endl;};
        static ICapteur* createCapteur(TypeCapteur type);
};

#endif