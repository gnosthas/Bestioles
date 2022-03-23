#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <vector>
#include <iostream>
// #include "Bestiole.h"
// #include "IBestiole.h"
// #include "Milieu.h"

// VISITOR DESIGN PATTERN

/* Est-ce qu'il faut redef destructeur si c'est pour une interface ? */
/* Est-ce qu'il faut redef destructeur si c'est pour une interface ? */
/* Est-ce qu'il faut mettre les comportements en const ? */
/* Est-ce qu'il faut redef les fonctions */

class IBestiole;
class Bestiole;
class Milieu;

class IComportement {
    public:
        virtual ~IComportement(){std::cout << "Destruction d'un comportement" << std::endl;};
        virtual void bougeSelonComportement(Milieu &m, Bestiole &b) = 0;
        virtual void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) = 0;
};


#endif