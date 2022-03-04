#include "iostream"
#include "concreteCreatorCochon.h"
#include "cochon.h"
using namespace std;


Mob* ConcreteCreatorCochon::createMob() const{
            cout << "Naissance d'un cochon" << endl;
            return new Cochon();
};

