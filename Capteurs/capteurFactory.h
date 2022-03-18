#ifndef CAPTEURFACTORY
#define CAPTEURFACTORY

#include <iostream>
#include "capteur.h"
using namespace std;

// Capteur Factory est une Classe virtuelle : aucun capteur ne peut être crée par appel à cet classe
// Les classes filles de CapteurFactory créent un capteur spécifique


class CapteurFactory {
    public:
        virtual ~CapteurFactory(){cout<<"Destruction capteur factory"<<endl;};
        virtual ICapteur* createCapteur() const = 0;
};

#endif


