#include "ComportementGregaire.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"

void ComportementGregaire::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins)
{
    if (!listeVoisins.empty()) {
        double orientationAll = 0;
        for (IBestiole* b2: listeVoisins) {
            orientationAll = orientationAll + b2->getOrientation();
        }
        orientationAll = orientationAll/listeVoisins.size();
        b.setOrientation(orientationAll);
    }
    
}

void ComportementGregaire::bougeSelonComportement(Milieu &m, Bestiole &b)
{
    std::vector<IBestiole*> listeVoisins = m.getBestiolesVues(b);
    adapterBestioleAVoisins(b, listeVoisins);
    bougeNormalement(b, m);
}