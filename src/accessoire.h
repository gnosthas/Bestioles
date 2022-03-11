#ifndef ACCESSOIRE
#define ACCESSOIRE

#include <iostream>
using namespace std;

// Déclare les operations que les accessoires concrets devront implémenter

class Accessoire {
    public:
        virtual ~Accessoire(){cout<<"Destruction d'un accessoire"<<endl;};
        // virtual void noise() const = 0;
};

#endif

