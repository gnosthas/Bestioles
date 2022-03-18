#include "ComportementGregaire.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"

void ComportementGregaire::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const
{
    double orientationAll = 0;
    for (IBestiole* b: listeVoisins) {
        orientationAll = orientationAll + b->getOrientation();
    }
    orientationAll = orientationAll/listeVoisins.size();
    b.setOrientation(orientationAll);
}

void ComportementGregaire::bougeSelonComportement(Milieu &m, Bestiole &b) const
{
    std::vector<IBestiole*> listeVoisins = m.getBestiolesVues(b);
    adapterBestioleAVoisins(b, listeVoisins);
    if (listeVoisins.size() == 0) {
        bougeNormalement(b, m);
    }
    else {
        bougeNormalement(b, m);
    }
}