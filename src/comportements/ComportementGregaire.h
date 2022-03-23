#ifndef _COMPORTEMENTGREGAIRE_H_
#define _COMPORTEMENTGREGAIRE_H_

#include "IComportement.h"

class ComportementGregaire : public IComportement {
    private:
        T* couleur;
    public:
        ComportementGregaire();
        ~ComportementGregaire() override;
        virtual T* getCouleur() const override;
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif