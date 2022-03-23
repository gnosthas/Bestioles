#ifndef _IBESTIOLE_H_
#define _IBESTIOLE_H_

#include <iostream>
#include <vector>
#include "UImg.h"

using namespace std;

class ICapteur; 


class Milieu;
class IComportement;
class IAccessoire;
class IBestiole{

protected : 
   static const double     AFF_SIZE; //Diamètre
   static const double     MAX_VITESSE; //Vitesse max
   static const double     LIMITE_VUE; //Vue max
   
   static int              next; //Permet d'incrémenter l'Id des bestioles

protected :
   int               identite;  //Id unique d'une bestiole
   int               x, y; //Position de la bestiole sur le cadrillage
   double            cumulX, cumulY; //Position réelle de la bestiole
   double            orientation; //Orientation de la Bestiole
   double            vitesse; //Vitesse de déplacement de la Besitole

   T               * couleur;
   int duree_vie; //Durée de vie de la Besitole
   double proba_clone; //probabilité de se cloner à chaque pas de simul
   double proba_death; //probabilité de mort lors d'une collision
   std::vector<IAccessoire*> listAccessoires; //liste d'accessoires associée à la bestiole
   IComportement* comportement; //Comportement de la bestiole
   std::vector<ICapteur*> listCapteurs; //liste de capteurs associée à la bestiole

   Milieu& milieu;



private :

   //Méthode virtuelle pure redéfinie dans Bestiole - Déplacement d'une bestiole
   virtual void bouge() = 0; 
   
   //Gère la collision entre les Bestioles.
   void collision(std::vector<IBestiole*> & removeBestioles);

   //Décrémente l'âge de la Bestiole
   void decrDureeVie(void);

   //Initialise les paramètres de la Bestiole (Vitesse, Orientation, ....) - Appelée dans le Constructeur
   void initBestiole();

   //Permet l'ajout d'accessoire à la liste d'accessoires de la Bestiole
   void ajout_Accessoires();

public :         

   virtual ~IBestiole( void );                              
   
   //Constructeur 
   IBestiole(Milieu& milieu, IComportement* comportement); 

   //Constructeur par copie d'une bestiole
   IBestiole(const IBestiole &ib); 


   void action(std::vector<IBestiole*> & appendBestioles, std::vector<IBestiole*> & removeBestioles ); //Méthode appelée sur la bestiole à chaque pas de simul

   virtual IBestiole* clone() const = 0; //DP Prototype  

   //Affichage d'une créature
   void draw( UImg & support );

   bool jeTeVois( const IBestiole & b ) const; //détermine si la créature détecte la créature passée en argument

   void initCoords( int xLim, int yLim ); //Place la bestiole à un endroit aléatoire avec limite horyzontale & verticale

   friend bool operator==( const IBestiole & b1, const IBestiole & b2 ); //Est-ce utile ? ou directement le faire pour les bestioles


   /////// Pointeur vers le milieu, 
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


   ///////////////////// CAPTEURS ////////////////////////
   void genererCapteurs();
};


#endif