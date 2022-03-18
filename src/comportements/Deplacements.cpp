#define _USE_MATH_DEFINES

#include "../Bestiole.h"
#include "../Milieu.h"
#include "Deplacements.h"
#include <cmath>
#include <cstdlib>

void bougeNormalement( Bestiole &b, Milieu &m )
{
    int xLim = m.getWidth();
    int yLim = m.getHeight(); 
    double         nx, ny;
    double         dx = cos( b.getOrientation() )*b.get_vitesse();
    double         dy = -sin( b.getOrientation() )*b.get_vitesse();
    int            cx, cy;


    cx = static_cast<int>( b.getCumulX() ); b.getCumulX() -= cx;
    cy = static_cast<int>( b.getCumulY() ); b.getCumulY() -= cy;

    nx = b.getX() + dx + cx;
    ny = b.getY() + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        b.setOrientation(M_PI - b.getOrientation());
        b.getCumulX() = 0.;
    }
    else {
        b.setX(static_cast<int>( nx ));
        b.getCumulX() += nx - b.getX();
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        b.setOrientation(-b.getOrientation());
        b.getCumulY() = 0.;
    }
    else {
        b.setY(static_cast<int>( ny ));
        b.getCumulY() += ny - b.getY();
    }

}