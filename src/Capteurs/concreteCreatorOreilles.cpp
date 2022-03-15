#include <iostream>
#include "concreteCreatorOreilles.h"
using namespace std;


Oreilles* ConcreteCreatorOreilles::createCapteur() const{
            cout << "Creation d'oreilles" << endl;
            return new Oreilles();
};

