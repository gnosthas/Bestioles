#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"

#include "Bestiole.h"
#include "Capteurs/capteurFactory.h"
#include "Accessoires/ConcreteCreatorNageoire.h"
#include "Accessoires/ConcreteCreatorCarapace.h"
#include <iostream>
#include <vector>

using namespace std;

class IBestiole;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;

   /*On fait le choix d'ajouter les paramètres proportions de chaque comportement et nombre 
   de créatures afin de générer notre configuration initiale au travers du constructeur*/
   double                  propGreg, propPeur, propKamik, propPrev, propMult;
   
   int                     nb_Bestioles;

   
   std::vector<IBestiole*>   listeBestioles;
 
   CapteurFactory            capteurs_factory;
   ConcreteCreatorNageoire   createur_nageoire;
   ConcreteCreatorCarapace   createur_carapace;

public :
   //Constructeur
   Milieu( int _width, int _height, int nb_Bestioles, double Greg, double Peur, double Kamik, double Prev, double Mult);
   
   //Destructeur
   ~Milieu( void );

   //Renvoie la liste des Bestioles présentes dans le milieu
   std::vector<IBestiole*>& getListeBestiole();

   //Appelée à chaque pas de simulation et fait appel à l'ensemble des méthodes relatives aux Bestioles
   void step( void );

   //Permet l'ajout et le retrait d'une Bestiole de la liste des Bestioles composant le Milieu
   void addBestiole( IBestiole* ib );
   void removeBestiole(IBestiole* ib);

   //Permet la naissance spontanée d'une Bestiole en fonction de la configuration du milieu 
   void naissanceSpontanee(void);

   //Renvoie le nombre de voisins de la bestiole passée en paramètre
   int nbVoisins( const IBestiole & ib );


   std::vector<IBestiole*> getBestiolesVues( IBestiole &b );

   ICapteur* createCapteur(TypeCapteur type);   // instances uniques des factories dans le milieu
   Nageoire* createNageoire();
   Carapace* createCarapace();

   //Getteurs
   int getWidth( void ) const;
   int getHeight( void ) const;
   int getNbBest( void ) const;
   double getPropGreg( void ) const;
   double getPropPeur( void ) const;
   double getPropKamik( void ) const;
   double getPropPrev( void ) const;
   double getPropMult( void ) const;
};


#endif
