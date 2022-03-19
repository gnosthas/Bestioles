#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

#include "Deplacements.h"
#include "../Bestiole.h"
#include "../Milieu.h"

void bougeNormalement( Bestiole &b, Milieu &m )
{   
    int xLim = m.getWidth();
    int yLim = m.getHeight(); 
    double         nx, ny;
    double         dx = cos( b.getOrientation() )*b.get_vitesse();
    double         dy = -sin( b.getOrientation() )*b.get_vitesse();
    int            cx, cy;


    cx = static_cast<int>( b.getCumulX() ); b.setCumulX(b.getCumulX() - cx);
    cy = static_cast<int>( b.getCumulY() ); b.setCumulY(b.getCumulY() - cy);

    nx = b.getX() + dx + cx;
    ny = b.getY() + dy + cy;
    
    if ( (nx < 0) || (nx > xLim - 1) ) {
        b.setOrientation(M_PI - b.getOrientation());
        b.setCumulX(0.);
    }
    else {
        b.setX(static_cast<int>( nx ));
        b.setCumulX( b.getCumulX() + nx - b.getX());
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        b.setOrientation(-b.getOrientation());
        b.setCumulX(0.);
    }
    else {
        b.setY(static_cast<int>( ny ));
        b.setCumulY(b.getCumulY() + ny - b.getY());
    }

}