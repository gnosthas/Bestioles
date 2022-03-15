#ifndef _COMPORTEMENTPREVOYANTE_H_
#define _COMPORTEMENTPREVOYANTE_H_

#include "IComportement.h"

class ComportementPrevoyante : public IComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
};

#endif