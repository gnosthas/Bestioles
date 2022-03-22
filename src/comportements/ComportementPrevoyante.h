#ifndef _COMPORTEMENTPREVOYANTE_H_
#define _COMPORTEMENTPREVOYANTE_H_

#include "IComportement.h"

class ComportementPrevoyante : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif