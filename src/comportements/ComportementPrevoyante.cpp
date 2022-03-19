#define _USE_MATH_DEFINES
#include "ComportementPrevoyante.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"
#include <cmath>

void ComportementPrevoyante::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const
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

        b.setOrientation(M_PI-plusProcheBest->getOrientation());
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