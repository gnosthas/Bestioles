#ifndef CAPTEUR
#define CAPTEUR

#include <iostream>
using namespace std;

// Déclare les operations que les capteurs concretes devront implémenter
// 


class ICapteur {   

    public:
        double alpha_m;
        double alpha_M;
        double delta_m;
        double delta_M;
        double gamma_m;
        double gamma_M ;
        float posX;
        float posY;

        virtual ~ICapteur(){cout<<"Destruction capteur"<<endl;};
        virtual void detection() const = 0;
};

#endif

