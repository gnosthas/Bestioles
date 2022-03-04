#include "iostream"
#include "concreteCreatorZombie.h"
#include "zombie.h"
using namespace std;


Mob* ConcreteCreatorZombie::createMob() const {
            cout << "Naissance d'un zombie" << endl;
            return new Zombie();
};