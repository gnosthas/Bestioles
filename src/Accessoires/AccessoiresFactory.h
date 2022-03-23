#ifndef ACCESSOIRESFACTORY
#define ACCESSOIRESFACTORY

// #include <iostream>
// using namespace std;

// AccessoiresFactory est une Classe virtuelle : aucun accessoire ne peut être crée par appel à cet classe
// Les classes filles de AccessoiresFactory créent un accessoir spécifique

#include "IAccessoire.h"

class AccessoiresFactory {
    public:
        virtual ~AccessoiresFactory(){std::cout << "Destruction d'un factory accessoire" << std::endl;};//cout<<"Destruction d'un Concrete creator d'accessoire"<<endl;};
        virtual IAccessoire* createAccessoire() const = 0;
};

#endif


