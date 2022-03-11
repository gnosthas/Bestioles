#include "iostream"
#include "concreteCreatorZombie.h"
using namespace std;

Zombie* ConcreteCreatorZombie::createMob() const {
            cout << "Naissance d'un zombie" << endl;
            return new Zombie();
};