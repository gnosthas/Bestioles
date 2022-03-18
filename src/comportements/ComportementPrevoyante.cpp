#include "ComportementPrevoyante.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "IBestiole.h"
#include "Deplacements.h"

void ComportementPrevoyante::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const
{
    for (IBestiole* b: listeVoisins) {

    }
}

void ComportementPrevoyante::bougeSelonComportement(Milieu &m, Bestiole &b) const
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