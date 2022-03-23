#ifndef IACCESSOIRE
#define IACCESSOIRE

#include <iostream>
// using namespace std;

// Déclare les operations que les accessoires concrets devront implémenter

class IAccessoire {
    public:
        virtual ~IAccessoire(){std::cout << "Destruction d'un accessoire" << std::endl;};//cout<<"Destruction d'un accessoire"<<endl;};
};

#endif

