#ifndef CAPTEUR
#define CAPTEUR

#include <iostream>
using namespace std;

// Déclare les operations que les capteurs concretes devront implémenter
// 
#include"../Milieu.h"

class ICapteur {   

    public:
        double alpha_min;
        double alpha_max;
        double delta_min;
        double delta_max;
        double gamma_m;
        double gamma_M ;
        float posX;
        float posY;

        virtual ~ICapteur(){std::cout<<"Destruction capteur"<<std::endl;};
        virtual bool detection(Milieu milieu) const = 0;
       // virtual bool proximity(double d_min, double d_max, Milieu milieu);
};



#endif

