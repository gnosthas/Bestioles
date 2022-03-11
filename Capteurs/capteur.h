#ifndef CAPTEUR
#define CAPTEUR

#include <iostream>
using namespace std;

// Déclare les operations que les capteurs concretes devront implémenter
// 


class ICapteur {
    public:
        virtual ~ICapteur(){cout<<"Destruction capteur"<<endl;};
        virtual void detection() const = 0;
};

#endif

