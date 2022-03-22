#ifndef CAPTEUR
#define CAPTEUR

#include <iostream>
using namespace std;

// Déclare les operations que les capteurs concretes devront implémenter
// 
#include"../Milieu.h"

class ICapteur {
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
        int id;
        virtual ~ICapteur(){cout<<"Destruction capteur"<<endl;};
        virtual void detection(Milieu milieu) const = 0;
};

#endif

