#include "iostream"
#include "concreteCreatorCamouflage.h"
#include "camouflage.h"
using namespace std;


Accessoire* ConcreteCreatorCamouflage::createAccessoire() const{
            cout << "Création d'un camouflage" << endl;
            return new Camouflage();
};

