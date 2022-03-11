#include "iostream"
#include "concreteCreatorCamouflage.h"

using namespace std;


Camouflage* ConcreteCreatorCamouflage::createAccessoire() const{
            cout << "Création d'un camouflage" << endl;
            return new Camouflage();
};

