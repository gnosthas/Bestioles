#include <iostream>
#include "concreteCreatorCochon.h"
#include "concreteCreatorZombie.h"
using namespace std;

int main(){ 
    // Pointeur MobFactory: création dynamique du Croncrete creator creator_cochon
    MobFactory* creator_cochon = new ConcreteCreatorCochon();  
    // Ici, on fait le choix d'une création statique
    ConcreteCreatorZombie creator_zombie;

    Mob* cochon = creator_cochon->createMob();
    cochon->noise();

    Mob* zombie = creator_zombie.createMob();
    zombie->noise();

    delete cochon;
    delete zombie;

    delete creator_cochon;
return 0;
}