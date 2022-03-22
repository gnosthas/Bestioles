#include "ComportementKamikaze.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"

#include <cmath>

/*
    Soit une bestiole.
    Elle fonce en permanace en direction de la bestiole la plus proche environnante.
*/

void ComportementKamikaze::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins)
{
    if (!listeVoisins.empty()) {
        double xb = b.getX() + b.getCumulX();
        double yb = b.getY() + b.getCumulY();
        double vb = b.get_vitesse();
        IBestiole* plusProcheBest;
        double distMin = 2000000;
        for (IBestiole* b2: listeVoisins) {
            double xb2 = b2->getX() + b2->getCumulX();
            double yb2 = b2->getY() + b2->getCumulY();
            double dist = sqrt(std::pow((xb-xb2),2)+std::pow((yb-yb2),2));
            if (dist < distMin) {
                distMin = dist;
                plusProcheBest = b2;
            }
        }
        double xb2 = plusProcheBest->getX() + plusProcheBest->getCumulX();
        double yb2 = plusProcheBest->getY() + plusProcheBest->getCumulY();
        double vb2 = plusProcheBest->get_vitesse();
        double directionB2 = atan((yb2-yb)/(xb2-xb));
        double newOrientation = (vb*directionB2 + vb2*plusProcheBest->getOrientation())/(vb+vb2);
        b.setOrientation(directionB2);
    }
    
}

void ComportementKamikaze::bougeSelonComportement(Milieu &m, Bestiole &b)
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