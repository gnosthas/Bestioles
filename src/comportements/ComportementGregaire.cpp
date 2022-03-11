#include "ComportementGregaire.h"
#include "Milieu.h"

void ComportementGregaire::bougeSelonComportement(Milieu &m, Bestiole &b) const
{
    std::vector<Bestiole>& bestiolesVues = m.getBestiolesVues(b);
    if (bestiolesVues.size() == 0) {
        bougeNormalement(b, m);
    }
    else {
        bougeNormalement(b, m);
    }
}