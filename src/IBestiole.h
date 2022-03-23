#ifndef _IBESTIOLE_H_
#define _IBESTIOLE_H_

#include <iostream>
#include <vector>
// #include "Accessoires/IAccessoire.h"
#include "UImg.h"

using namespace std;

// class ICapteur; //capteurs

class Milieu;
class IComportement;
class IAccessoire;
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
   int duree_vie; //Age de la bestiole qui augmente à chaque pas de simulation
   double proba_clone; //proba de se cloner à chaque pas de simul
   double proba_death; //proba de mort lors d'une collision
   // std::vector<ICapteur*> listCapteurs; //liste de capteurs associée à la bestiole
   std::vector<IAccessoire*> listAccessoires; //liste d'accessoires associée à la bestiole
   IComportement* comportement; //Comportement de la bestiole



private :

   //Déplace la créature dans le milieu
   virtual void bouge(Milieu &milieu) = 0; 
   
   /*Gère la collision entre les créatures. La collision se fait entre deux cercles ? deux ellipses ?
   Parcours la liste de toutes les autres créatures ?
   En cas de collision, 1] proba mort 2] changement d'orientation à l'opposée */
   void collision(Milieu &milieu, std::vector<IBestiole*> & removeBestioles);

   //Augmente l'age de la bestiole --> appelé à chaque pas de simulation
   void decrDureeVie(void);

   void initBestiole(void);

   std::vector<IAccessoire*> ajout_Accessoires();

public :         

   virtual ~IBestiole( void );                              // Destructeur

   
   IBestiole(); ////////// TEMPORAIRE POUR TEST COMPILATION
   IBestiole(IComportement* comportement); //Constructeur d'une bestiole

   ////////// TEMPORAIRE POUR TEST COMPILATION
   IBestiole(const IBestiole &ib); //Constructeur par copie d'une bestiole

   void action( Milieu & monMilieu, std::vector<IBestiole*> & appendBestioles, std::vector<IBestiole*> & removeBestioles ); //Méthode appelée sur la bestiole à chaque pas de simul

   virtual IBestiole* clone() const = 0; //DP Prototype  

   ////////// TEMPORAIRE POUR TEST COMPILATION
   // void draw( UImg & support, Milieu & milieu ); //Affichage d'une créature
   void draw( UImg & support );

   bool jeTeVois( const IBestiole & b ) const; //détermine si la créature détecte la créature passée en argument

   void initCoords( int xLim, int yLim ); //Place la bestiole à un endroit aléatoire avec limite horyzontale & verticale

   friend bool operator==( const IBestiole & b1, const IBestiole & b2 ); //Est-ce utile ? ou directement le faire pour les bestioles

   /////////////////////////  GETTEURS / SETTEURS //////////////////////////////

   virtual double get_proba_death(void) const;
   int getX() const;
   int getY() const;
   double getCumulX() const;
   double getCumulY() const;
   virtual double get_vitesse(void) const;
   virtual double getOrientation(void) const;
   int getIdentite(void) const;
   IComportement* getComportement(void) const;
   int getDureeVie(void) const;

   void setColor(int r, int g, int b);
   void setX(int x);
   void setY(int y);
   void setCumulX(double cx);
   void setCumulY(double cy);
   virtual void setVitesse(double v);
   void setDureeVie(int duree_vie);
   void setOrientation(double o);
};


#endif