#ifndef IACCESSOIRE
#define IACCESSOIRE

#include <iostream>
using namespace std;

// Déclare les operations que les accessoires concrets devront implémenter

class IAccessoire {
    public:
        virtual ~IAccessoire(){cout<<"Destruction d'un accessoire"<<endl;};
        // virtual void noise() const = 0;
};

#endif

