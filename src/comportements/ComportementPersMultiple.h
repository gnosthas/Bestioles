#ifndef _COMPORTEMENTPERSMULTIPLE_H_
#define _COMPORTEMENTPERSMULTIPLE_H_

#include "IComportement.h"

class ComportementPersMultiple : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const override;
};

#endif