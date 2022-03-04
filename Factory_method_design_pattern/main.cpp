#include <iostream>
#include "concreteCreatorCochon.h"
#include "concreteCreatorZombie.h"
using namespace std;

Mob* naissance_cochon(){
    // Pointeur MobFactory: création dynamique du Croncrete creator creator_cochon
    MobFactory* creator_cochon = new ConcreteCreatorCochon(); 
    // Pointeur Mob : création dynamique d'un cochon
    Mob* cochon = creator_cochon->createMob();
    // Appel au destructeur de ConcreteCreatorCochon
    delete creator_cochon;
    return cochon;
}

Mob* naissance_zombie(){
    // Ici, on fait le choix d'une création statique
    ConcreteCreatorZombie creator_zombie;
    Mob* zombie = creator_zombie.createMob();
    return  zombie;
}

int main(){  
    Mob* cochon = naissance_cochon();
    cochon->noise();

    Mob* zombie = naissance_zombie();
    zombie->noise();

    delete cochon;
    delete zombie;
return 0;
}