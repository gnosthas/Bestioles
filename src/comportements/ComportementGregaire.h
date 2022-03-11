#ifndef _COMPORTEMENTGREGAIRE_H_
#define _COMPORTEMENTGREGAIRE_H_

#include "IComportement.h"

class ComportementGregaire : public iComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
};

#endif