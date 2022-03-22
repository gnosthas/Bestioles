#ifndef _COMPORTEMENTPERSMULTIPLE_H_
#define _COMPORTEMENTPERSMULTIPLE_H_

#include "IComportement.h"
#include <map>

class ComportementPersMultiple : public IComportement {
    private :
        double proba_changer_comportement = 0.05;
        std::map<int,int> comportementBestioles;
    public:
        std::vector<IComportement*> comportements;
        ComportementPersMultiple(std::vector<IComportement*> comportements);
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif