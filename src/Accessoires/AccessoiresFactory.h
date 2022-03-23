#ifndef ACCESSOIRESFACTORY
#define ACCESSOIRESFACTORY

// AccessoiresFactory est une Classe virtuelle
// Les classes filles de AccessoiresFactory créent des accessoirs spécifique

#include "IAccessoire.h"

class AccessoiresFactory {
    public:
        virtual ~AccessoiresFactory(){std::cout << "dest factory accessoire" << std::endl;};//cout<<"Destruction d'un Concrete creator d'accessoire"<<endl;};
        virtual IAccessoire* createAccessoire() const = 0;
};

#endif


