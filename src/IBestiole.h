#ifndef _IBESTIOLE_H_
#define _IBESTIOLE_H_

#include <iostream>
#include <vector>

#include "Accessoires/IAccessoire.h"
#include "comportements/IComportement.h"
#include "UImg.h"

using namespace std;

class ICapteur; //capteurs
class Milieu;
class IComportement;

class IBestiole{

protected : 
   static const double     AFF_SIZE; //diamètre
   static const double     MAX_VITESSE; //vitesse max
   static const double     LIMITE_VUE; //vue max
   
   static int              next; //permet d'incrémenter l'Id des bestioles

protected :
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
   std::vector<IAccessoire*> listAccessoires; //liste d'accessoires associée à la bestiole
   IComportement* comportement; //Comportement de la bestiole



private :

   //Augmente l'age de la bestiole --> appelé à chaque pas de simulation
   void incr_age(void){++age;};

   //Déplace la créature dans le milieu
   void bouge(Milieu &milieu); 
   
   /*Gère la collision entre les créatures. La collision se fait entre deux cercles ? deux ellipses ?
   Parcours la liste de toutes les autres créatures ?
   En cas de collision, 1] proba mort 2] changement d'orientation à l'opposée */
   void collision(Milieu &milieu);

   void initBestiole(void);

public :         

   virtual ~IBestiole( void );                              // Destructeur

   IBestiole(IComportement* comportement); //Constructeur d'une bestiole

   IBestiole(const IBestiole &ib); //Constructeur par copie d'une bestiole

   void action( Milieu & monMilieu ); //Méthode appelée sur la créature à chaque pas de simul

   virtual IBestiole* clone() const = 0; //DP Prototype  

   void draw( UImg & support, Milieu & milieu ); //Affichage d'une créature

   bool jeTeVois( const IBestiole & b ) const; //détermine si la créature détecte la créature passée en argument

   void initCoords( int xLim, int yLim ); //Place la bestiole à un endroit aléatoire avec limite horyzontale & verticale

   friend bool operator==( const IBestiole & b1, const IBestiole & b2 ); //Est-ce utile ? ou directement le faire pour les bestioles

   /////////////////////////  GETTEURS / SETTEURS //////////////////////////////

   virtual double get_proba_death(void) const;
   int getX() const;
   int getY() const;
   virtual double get_vitesse(void) const;
   virtual double getOrientation(void) const;
   int getIdentite(void) const;
   IComportement* getComportement(void) const;
   int getAge(void) const;
   void setColor(int r, int g, int b);
   virtual void setVitesse(double v);

};


#endif