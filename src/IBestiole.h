#ifndef _IBESTIOLE_H_
#define _IBESTIOLE_H_

#include <iostream>
#include <vector>

#include "Accessoires/IAccessoire.h"
#include "comportements/IComportement.h"
#include "UImg.h"

using namespace std;

class ICapteur;

class IBestiole{

protected :
   static const double     AFF_SIZE; //diamètre
   static const double     MAX_VITESSE; //vitesse max
   static const double     LIMITE_VUE; //vue max
   
   static int              next; //permet d'incrémenter l'Id des bestioles

public :
   int               identite;  //Id unique d'une bestiole
   int               x, y; //Position de la bestiole sur le cadrillage
   double            cumulX, cumulY; //Position réelle de la bestiole
   double            orientation; 
   double            vitesse; 

   T               * couleur;
   int age; //Age de la bestiole qui augmente à chaque pas de simulation
   double proba_clone; //proba de se cloner à chaque pas de simul
   double proba_death; //proba de mort lors d'une collision
   std::vector<ICapteur*> listCapteurs; //liste de capteurs associée à la bestiole
   std::vector<IAccessoire*> listAccesoires; //liste d'accessoires associée à la bestiole
   IComportement* comportement; //Comportsement de la bestiole



private :

   //Déplace la créature dans le milieu
   void bouge(Milieu &milieu); 
   
   /*Gère la collision entre les créatures. La collision se fait entre deux cercles ? deux ellipses ?
   Parcours la liste de toutes les autres créatures ?
   En cas de collision, 1] proba mort 2] changement d'orientation à l'opposée */
   void collision(Milieu &milieu);

   //Augmente l'age de la bestiole --> appelé à chaque pas de simul
   void incrAge();


public :                                           // Forme canonique :
   ~IBestiole( void );                              // Destructeur

   IBestiole(IComportement* comportement);

   virtual IBestiole* clone() const = 0; //DP Prototype  

   void action( Milieu & monMilieu );


   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   IBestiole* clone(Bestiole* b);
};


#endif