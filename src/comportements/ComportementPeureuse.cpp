#include "ComportementPeureuse.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"

/*
    Soit une bestiole.
    Si le nombre de bestioles environnantes depasse son seuil d'agoraphobie : elle passe dans l'etat peur pendant dureePeur steps et son orientation devient l'oppose.
    Si une bestiole est dans l'etat peur, sa vitesse de deplacement est multiplie par accelerationPeur.
    Dans les 25% du debut de son etat peur, la bestiole ne peut plus avoir a nouveau peur, par contre si le nombre de bestioles environnantes est toujours trop haut
        lors d'une step, son etat peur est prolonge d'une step.
*/

void ComportementPeureuse::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins)
{
    if (listeVoisins.size() >= peurDesNbBestioles) {
        if (dureePeur.find(b.getIdentite()) != dureePeur.end()) {
             if (dureePeur[b.getIdentite()] < dureeEtatPeur/4) {
                    dureePeur[b.getIdentite()] = dureeEtatPeur;
                    b.setOrientation(M_PI + b.getOrientation());
             }
        }
        else {
            dureePeur[b.getIdentite()] = dureeEtatPeur;
            b.setOrientation(M_PI + b.getOrientation());
        }
    }
    else {
        if (dureePeur.find(b.getIdentite()) != dureePeur.end()) {
            if (dureePeur[b.getIdentite()] > 0) {
                --dureePeur[b.getIdentite()];
            }
            else dureePeur.erase(b.getIdentite());
        }
    }
}

void ComportementPeureuse::bougeSelonComportement(Milieu &m, Bestiole &b)
{
    std::vector<IBestiole*> listeVoisins = m.getBestiolesVues(b);
    adapterBestioleAVoisins(b, listeVoisins);
    if (dureePeur.find(b.getIdentite()) != dureePeur.end() && dureePeur[b.getIdentite()] > 0) {
        double v = b.get_vitesse();
        b.setVitesse(v*accelerationPeur);
        bougeNormalement(b, m);
        b.setVitesse(v);
    }
    else {
        bougeNormalement(b, m);
    }
}