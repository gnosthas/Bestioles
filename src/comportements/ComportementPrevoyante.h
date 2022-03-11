#ifndef _COMPORTEMENTPREVOYANTE_H_
#define _COMPORTEMENTPREVOYANTE_H_

#include "IComportement.h"

class ComportementPrevoyante : public iComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
};

#endif