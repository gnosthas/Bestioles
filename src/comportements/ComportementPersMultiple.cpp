#include "ComportementPersMultiple.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"
#include <vector>
#include <random>


ComportementPersMultiple::ComportementPersMultiple(std::vector<IComportement*> listeComportements):comportements(listeComportements) {}

void ComportementPersMultiple::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins)
{
}

/* Definir les fonctions et les variables en variables de la classe */
void ComportementPersMultiple::bougeSelonComportement(Milieu &m, Bestiole &b)
{   
    std::random_device dev;
    std::mt19937 rng(dev());
    if (comportementBestioles.find(b.getIdentite()) == comportementBestioles.end()) {
        std::uniform_int_distribution<std::mt19937::result_type> distCompSiz(0,comportements.size()-1);
        comportementBestioles[b.getIdentite()] = distCompSiz(rng);
    }
    else {
        std::uniform_int_distribution<std::mt19937::result_type> prob(0,100);
        if (prob(rng) < proba_changer_comportement*100) {
            std::uniform_int_distribution<std::mt19937::result_type> distCompSiz(0,comportements.size()-1);
            auto a = distCompSiz(rng);
            std::cout << "La bestiole " << b.getIdentite() << " a le nouveau comportement : " << a << std::endl;
            comportementBestioles[b.getIdentite()] = a;
        }
    }
    comportements.at(comportementBestioles[b.getIdentite()])->bougeSelonComportement(m, b);
}