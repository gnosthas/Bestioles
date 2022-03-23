#ifndef CAPTEUR
#define CAPTEUR

#include <iostream>
using namespace std;

// Déclare les operations que les capteurs concretes devront implémenter
// 
#include"../Milieu.h"

class ICapteur {   

    public:
        float posX;
        float posY;

        virtual ~ICapteur(){std::cout<<"Destruction capteur"<<std::endl;};
        virtual bool detection(Milieu milieu) const = 0;
       // virtual bool proximity(double d_min, double d_max, Milieu milieu);
};



#endif

