#ifndef _COMPORTEMENTPREVOYANTE_H_
#define _COMPORTEMENTPREVOYANTE_H_

#include "iComportement.h"

class ComportementPrevoyante : public iComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
}

#endif