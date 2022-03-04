#ifndef MOB
#define MOB

#include <iostream>
using namespace std;

// Déclare les operations que les créatures concretes devront implémentés

class Mob {
    public:
        virtual ~Mob(){cout<<"Destruction mob"<<endl;};
        virtual void noise() const = 0;
};

#endif

