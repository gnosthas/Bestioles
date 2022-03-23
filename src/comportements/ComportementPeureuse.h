#ifndef _COMPORTEMENTPEUREUSE_H_
#define _COMPORTEMENTPEUREUSE_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <map>

#include "IComportement.h"

class ComportementPeureuse : public IComportement {
    private:
        T* couleur;
        int peurDesNbBestioles = 1; //La bestiole a peur des que le nombre de bestioles environnantes dépasse ce nombre
        int accelerationPeur = 2; //La bestiole a peur des que le nombre de bestioles environnantes dépasse ce nombre
        int dureeEtatPeur = 15; //La bestiole a peur des que le nombre de bestioles environnantes dépasse ce nombre
        std::map<int,int> dureePeur;
    public:
        ComportementPeureuse();
        ~ComportementPeureuse() override;
        virtual T* getCouleur() const override;
        void bougeSelonComportement(Milieu &m, Bestiole &b) override;
        void adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) override;
};

#endif