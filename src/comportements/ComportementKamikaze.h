#ifndef _COMPORTEMENTKAMIKAZE_H_
#define _COMPORTEMENTKAMIKAZE_H_

#include "IComportement.h"

class ComportementKamikaze : public iComportement {
    public:
        void bougeSelonComportement(Milieu &m, Bestiole &b) const override;
};

#endif