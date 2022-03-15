#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include "Bestiole.h"
#include "Milieu.h"
#include "deplacements.cpp"

// VISITOR DESIGN PATTERN

/* Est-ce qu'il faut redef destructeur si c'est pour une interface ? */
/* Est-ce qu'il faut redef destructeur si c'est pour une interface ? */
/* Est-ce qu'il faut mettre les comportements en const ? */
/* Est-ce qu'il faut redef les fonctions */

class IComportement {
    public:
        virtual ~IComportement(){cout<<"Destruction comportement"<<endl;};
        virtual void bougeSelonComportement(Milieu &m, Bestiole &b) const = 0;
}


#endif