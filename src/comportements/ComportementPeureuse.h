#ifndef _COMPORTEMENTPEUREUSE_H_
#define _COMPORTEMENTPEUREUSE_H_

#include "comportements/iComportement.h"

class ComportementPeureuse : public iComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
}

#endif