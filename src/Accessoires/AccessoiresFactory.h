#ifndef ACCESSOIRESFACTORY
#define ACCESSOIRESFACTORY

// AccessoiresFactory est une Classe virtuelle
// Les classes filles de AccessoiresFactory créent des accessoirs spécifiques

#include "IAccessoire.h"

class AccessoiresFactory {
    protected:
        double PSI_MAX = 2;
        double OMEGA_MAX = 2;
        double ETA_MAX = 2;
        double NU_MAX = 2;
    public:
        virtual ~AccessoiresFactory(){std::cout << "dest factory accessoire" << std::endl;};//cout<<"Destruction d'un Concrete creator d'accessoire"<<endl;};
        virtual IAccessoire* createAccessoire() = 0;
};

#endif


