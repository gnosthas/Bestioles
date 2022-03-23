#ifndef IACCESSOIRE
#define IACCESSOIRE

#include <iostream>
// Déclare les operations que les accessoires concrets devront implémenter

class IAccessoire {
    public:
        virtual ~IAccessoire(){std::cout << "dest accessoire" << std::endl;};
};

#endif

