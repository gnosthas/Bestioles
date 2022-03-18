#define _USE_MATH_DEFINES

#include "../Bestiole.h"
#include "../Milieu.h"
#include <cmath>
#include <cstdlib>

void bougeNormalement( Bestiole &b, Milieu &m )
{
    int xLim = m.getWidth();
    int yLim = m.getHeight(); 
    double         nx, ny;
    double         dx = cos( b.orientation )*b.vitesse;
    double         dy = -sin( b.orientation )*b.vitesse;
    int            cx, cy;


    cx = static_cast<int>( b.cumulX ); b.cumulX -= cx;
    cy = static_cast<int>( b.cumulY ); b.cumulY -= cy;

    nx = b.x + dx + cx;
    ny = b.y + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        b.orientation = M_PI - b.orientation;
        b.cumulX = 0.;
    }
    else {
        b.x = static_cast<int>( nx );
        b.cumulX += nx - b.x;
    }

    if ( (ny < 0) || (ny > yLim - 1) ) {
        b.orientation = -b.orientation;
        b.cumulY = 0.;
    }
    else {
        b.y = static_cast<int>( ny );
        b.cumulY += ny - b.y;
    }

}