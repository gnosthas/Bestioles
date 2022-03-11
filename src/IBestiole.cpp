#include <iostream>
#include <vector>

#include "IBestiole.h"
#include "UImg.h"

using namespace std;


class IBestiole{

const double      IBestiole::AFF_SIZE = 8.0;
const double      IBestiole::MAX_VITESSE = 10.0;
const double      IBestiole::LIMITE_VUE = 30.0;


int               IBestiole::next = 0;



void bouge(Milieu &milieu); 

void collision(Milieu &milieu, );
void incrAge();
IBestiole( void );
IBestiole(*Icomportement comportement);
IBestiole( const IBestiole &ib ); 
~IBestiole( void );
void *IBestiole clone();
void action( Milieu & monMilieu );
void draw( UImg & support );
bool jeTeVois( const Bestiole & b ) const;
void initCoords( int xLim, int yLim );
friend bool operator==( const Bestiole & b1, const Bestiole & b2 );



};

#endif