#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"

#include "Bestiole.h"
#include "Capteurs/capteurFactory.h"
#include <iostream>
#include <vector>

using namespace std;

class IBestiole;

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;

   double                  propGreg, propPeur, propKamik, propPrev, propMult;
   
   int                     nb_Bestioles;

   
   std::vector<IBestiole*>   listeBestioles;
 
   CapteurFactory            factory;

public :
   Milieu( int _width, int _height, int nb_Bestioles, double Greg, double Peur, double Kamik, double Prev, double Mult);
   ~Milieu( void );

   int getWidth( void ) const;
   int getHeight( void ) const;
   int getNbBest( void ) const;
   double getPropGreg( void ) const;
   double getPropPeur( void ) const;
   double getPropKamik( void ) const;
   double getPropPrev( void ) const;
   double getPropMult( void ) const;
   


   std::vector<IBestiole*>& getListeBestiole();
   void step( void );

   void addBestiole( IBestiole* ib );
   void removeBestiole(IBestiole* ib);

   void naissanceSpontanee(void);

   int nbVoisins( const IBestiole & ib );

   std::vector<IBestiole*> getBestiolesVues( IBestiole &b );



   ICapteur* createCapteur(TypeCapteur type);
};


#endif
