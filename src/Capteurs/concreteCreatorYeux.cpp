#include <iostream>
#include "concreteCreatorYeux.h"
using namespace std;


Yeux* ConcreteCreatorYeux::createCapteur() const{
            cout << "Creation d'yeux" << endl;
            return new Yeux();
};

