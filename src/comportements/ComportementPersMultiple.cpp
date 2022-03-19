#include "ComportementPersMultiple.h"
#include "../Milieu.h"
#include "../Bestiole.h"
#include "../IBestiole.h"
#include "Deplacements.h"
#include <vector>
#include <map>
#include <random>

double proba_changer_comportement = 0.05;
std::map<int,int> comportementBestioles;
std::random_device dev;
std::mt19937 rng(dev());

ComportementPersMultiple::ComportementPersMultiple(std::vector<IComportement*> listeComportements):comportements(listeComportements) {}

void ComportementPersMultiple::adapterBestioleAVoisins(Bestiole &b, std::vector<IBestiole*>& listeVoisins) const
{
}

/* Definir les fonctions et les variables en variables de la classe */
void ComportementPersMultiple::bougeSelonComportement(Milieu &m, Bestiole &b) const
{
    if (comportementBestioles.find(b.getIdentite()) == comportementBestioles.end()) {
        std::uniform_int_distribution<std::mt19937::result_type> distCompSiz(0,comportements.size()-1);
        comportementBestioles[b.getIdentite()] = distCompSiz(rng);
    }
    else {
        std::uniform_int_distribution<std::mt19937::result_type> prob(0,100);
        if (prob(rng) < proba_changer_comportement*100) {
            std::uniform_int_distribution<std::mt19937::result_type> distCompSiz(0,comportements.size()-1);
            auto a = distCompSiz(rng);
            std::cout << "New comportement : " << a << std::endl;
            comportementBestioles[b.getIdentite()] = a;
        }
    }
    double clonnage = ((rand() % 1001) + 1) / 1000.0;
    comportements.at(comportementBestioles[b.getIdentite()])->bougeSelonComportement(m, b);
}