#ifndef _COMPORTEMENTPREVOYANTE_H_
#define _COMPORTEMENTPREVOYANTE_H_

#include "IComportement.h"

class ComportementPrevoyante : public IComportement {
    private:
        T* couleur;
    public:
        ComportementPrevoyante();
        ~ComportementPrevoyante() override;
        virtual T* getCouleur() const override;
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif