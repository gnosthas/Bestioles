#ifndef _COMPORTEMENTPEUREUSE_H_
#define _COMPORTEMENTPEUREUSE_H_

#define _USE_MATH_DEFINES
#include <cmath>

#include "IComportement.h"

class ComportementPeureuse : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const override;
};

#endif