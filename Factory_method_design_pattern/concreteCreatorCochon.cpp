#include "iostream"
#include "concreteCreatorCochon.h"
using namespace std;


Cochon* ConcreteCreatorCochon::createMob() const{
            cout << "Naissance d'un cochon" << endl;
            return new Cochon();
};

