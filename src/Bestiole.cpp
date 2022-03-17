#include "Bestiole.h"

#include <cstdlib>
#include <cmath>


Bestiole::Bestiole(IComportement* comportement):IBestiole(comportement){}


Bestiole::Bestiole(const Bestiole & b):IBestiole(b){}


IBestiole* Bestiole::clone() const{
    return new Bestiole(*this);
}

