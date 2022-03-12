#ifndef MOBFACTORY
#define MOBFACTORY

#include <iostream>
using namespace std;

// Mob Factory est une Classe virtuelle : aucun mob ne peut être crée par appel à cet classe
// Les classes filles de MobFactory créent un mob spécifique

#include "mob.h"

class MobFactory {
    public:
        virtual ~MobFactory(){cout<<"Destruction mob factory"<<endl;};
        virtual Mob* createMob() const = 0;
};

#endif


