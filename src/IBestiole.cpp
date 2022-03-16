#include <iostream>
#include <vector>

#include "comportements/IComportement.h"
#include "Milieu.h"
#include "UImg.h"
#include "IBestiole.h"

#include <cstdlib>
#include <cmath>
using namespace std;

const double      IBestiole::AFF_SIZE = 8.0;
const double      IBestiole::MAX_VITESSE = 10.0;
const double      IBestiole::LIMITE_VUE = 30.0;


int               IBestiole::next = 0;



///////////// Initialise la bestiole : Id, position, vitesse, couleur, ... /////////////////
void IBestiole::initBestiole(){
   this->identite = ++next;
   this->x = this->y = 0;
   this->cumulX = this->cumulY = 0.;

   // vitesse initiale aléatoire
   this->vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   // définit la couleur de la bestiole r , g , b
   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   this->proba_death = ((rand() % 101))/100.0 ;// valeur entre 0 et 1
   this->age = 0; //Toute bestiole même durée de vie du coup ? ou alors crée champ durée de vie et on l'initialise aléatoirement puis il décroit à chaque pas de simul
   this->proba_clone= 0.01; 
}

///////////////////////// Constructeur d'une bestiole /////////////////////////////
IBestiole::IBestiole(IComportement* comportement) : comportement(comportement){

   initBestiole();
//    switch (comportement->getComportementType())
//    {
//    // couleur en fonction du comportement ? setColor(r,g,b) mais il faut un enumtype des comportements !
// }
}


///////////////////////// Constructeur par copie de la bestiole /////////////////////////////
IBestiole::IBestiole( const IBestiole & ib ) : identite(++next), x(ib.x), y(ib.y), 
cumulX(ib.cumulX), cumulY(ib.cumulY), vitesse(ib.vitesse), orientation(ib.orientation), 
proba_death(ib.proba_death), age(ib.age), proba_clone(ib.proba_clone), listCapteurs(ib.listCapteurs),
 listAccessoires(ib.listAccessoires),comportement(ib.comportement)
{
   couleur = new T[ 3 ];
   memcpy( couleur, ib.couleur, 3*sizeof(T) );
}






