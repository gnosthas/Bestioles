#ifndef _COMPORTEMENTGREGAIRE_H_
#define _COMPORTEMENTGREGAIRE_H_

#include "IComportement.h"

class ComportementGregaire : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif