#ifndef _COMPORTEMENTPEUREUSE_H_
#define _COMPORTEMENTPEUREUSE_H_

#include "IComportement.h"

class ComportementPeureuse : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
};

#endif