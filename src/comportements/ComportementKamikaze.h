#ifndef _COMPORTEMENTKAMIKAZE_H_
#define _COMPORTEMENTKAMIKAZE_H_

#include "IComportement.h"

class ComportementKamikaze : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif