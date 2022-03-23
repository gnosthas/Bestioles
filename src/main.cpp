#include "Aquarium.h"
#include "Milieu.h"
#include "ConcreteCreatorBestiole.h"
#include "comportements/ComportementPeureuse.h"
#include "comportements/ComportementGregaire.h"
#include "comportements/ComportementKamikaze.h"
#include "comportements/ComportementPrevoyante.h"
#include "comportements/ComportementPersMultiple.h"
#include "Accessoires/ConcreteCreatorNageoire.h"

#include <iostream>
#include <vector>


using namespace std;


int main()
{

///////////////////////////////////////////////LOIC COMPILATION ////////////////////////
   // Aquarium       ecosysteme( 640, 480, 120 );
   // ConcreteCreatorBestiole creator_bestiole;
   // IComportement *prev = new ComportementPrevoyante();
   // IComportement *greg = new ComportementGregaire();
   // IComportement *kami = new ComportementKamikaze();
   // IComportement *peur = new ComportementPeureuse();
   // std::vector<IComportement*> comportements;
   // comportements.push_back(prev);
   // comportements.push_back(greg);
   // comportements.push_back(kami);
   // comportements.push_back(peur);
   // ComportementPersMultiple *pers = new ComportementPersMultiple(comportements);
   // comportements.push_back(pers);
   // std::cout<<"taille vect persmult : " << pers->comportements.size() << std::endl;;

   // int nbPrevoyantes = 5; 
   // int nbPeureuses = 5; 
   // int nbGregaires = 5; 
   // int nbKamikazes = 5; 
   // int nbPersMult = 5; 
   // for ( int i = 1; i <= nbPrevoyantes; ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(prev);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // for ( int i = 1; i <= nbPeureuses; ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(peur);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // for ( int i = 1; i <= nbGregaires; ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(greg);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // for ( int i = 1; i <= nbKamikazes; ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(kami);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // for ( int i = 1; i <= nbPersMult; ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(pers);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // ecosysteme.run();
   // delete peur;




////////////////////////////////CLEMENT COMPILATION POUR CLONAGE ET MORT DES BESTIOLES ///////////
   // Aquarium       ecosysteme( 640, 480, 30,  30, 0.20, 0.20, 0.20, 0.20, 0.20);
   // ConcreteCreatorBestiole creator_bestiole;
   // ComportementGregaire *peur = new ComportementGregaire();
   // for ( int i = 1; i <= ecosysteme.getMilieu().getNbBest(); ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(peur);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   // ecosysteme.run();
   // delete peur;


////////////////////////////CLEMENT COMPILATION TEST CONFIGURATION ////////////////////////


// /////////////////////// CREATION DES COMPORTEMENTS /////////////////////////////
//    IComportement *prev = new ComportementPrevoyante();
//    IComportement *greg = new ComportementGregaire();
//    IComportement *kami = new ComportementKamikaze();
//    IComportement *peur = new ComportementPeureuse();
//    std::vector<IComportement*> comportements;
//    comportements.push_back(prev);
//    comportements.push_back(greg);
//    comportements.push_back(kami);
//    comportements.push_back(peur);
//    ComportementPersMultiple *pers = new ComportementPersMultiple(comportements);
//    comportements.push_back(pers);
//    std::cout<<"taille vect persmult : " << pers->comportements.size() << std::endl;;


//    ///////////////////////// CREATION DE LA CONFIGURATION DE LA POPULATION INITIALE//////////////////
//    // Nombre Bestioles = 30
//    // Proportion gregaire = kamikaze = peureuse = prevoyante = personnalités mult = 0.20
//    Aquarium       ecosysteme( 640, 480, 120,  30, 0.20, 0.20, 0.20, 0.20, 0.20);
//    ConcreteCreatorBestiole creator_bestiole;

//    for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropGreg()); ++i ){
//       Bestiole* bestiole = creator_bestiole.createBestiole(greg);
//       ecosysteme.getMilieu().addBestiole(bestiole);
//    }
//    for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPeur()); ++i ){
//       Bestiole* bestiole = creator_bestiole.createBestiole(peur);
//       ecosysteme.getMilieu().addBestiole(bestiole);
//    }
//    for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropKamik()); ++i ){
//       Bestiole* bestiole = creator_bestiole.createBestiole(kami);
//       ecosysteme.getMilieu().addBestiole(bestiole);
//    }
//    for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPrev()); ++i ){
//       Bestiole* bestiole = creator_bestiole.createBestiole(prev);
//       ecosysteme.getMilieu().addBestiole(bestiole);
//    }
//    for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropMult()); ++i ){
//       Bestiole* bestiole = creator_bestiole.createBestiole(pers);
//       ecosysteme.getMilieu().addBestiole(bestiole);
//    }
//    ecosysteme.run();
//    delete peur;


////////////////////////////ETIENNE VERIFICATION BONNE DESTRUCTION DE TOUS LES OBJETS UTILISES ////////////////////////


/////////////////////// CREATION DES COMPORTEMENTS /////////////////////////////
   IComportement *prev = new ComportementPrevoyante();
   IComportement *greg = new ComportementGregaire();
   IComportement *kami = new ComportementKamikaze();
   IComportement *peur = new ComportementPeureuse();
   std::vector<IComportement*> comportements;
   comportements.push_back(prev);
   comportements.push_back(greg);
   comportements.push_back(kami);
   comportements.push_back(peur);
   ComportementPersMultiple *pers = new ComportementPersMultiple(comportements);
   comportements.push_back(pers);
   // std::cout<<"taille vect persmult : " << pers->comportements.size() << std::endl;;

   ///////////////////////// CREATION DE LA CONFIGURATION DE LA POPULATION INITIALE//////////////////
   // Nombre Bestioles = 30
   // Proportion gregaire = kamikaze = peureuse = prevoyante = personnalités mult = 0.20
   Aquarium       ecosysteme( 640, 480, 30,  30, 0.20, 0.20, 0.20, 0.20, 0.20);
   ConcreteCreatorBestiole creator_bestiole;

   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropGreg()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),greg);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPeur()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),peur);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropKamik()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),kami);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropPrev()); ++i ){
      Bestiole* bestiole = creator_bestiole.createBestiole(ecosysteme.getMilieu(),prev);
      ecosysteme.getMilieu().addBestiole(bestiole);
   }
   // for ( int i = 1; i <= floor(ecosysteme.getMilieu().getNbBest()*ecosysteme.getMilieu().getPropMult()); ++i ){
   //    Bestiole* bestiole = creator_bestiole.createBestiole(pers);
   //    ecosysteme.getMilieu().addBestiole(bestiole);
   // }
   ecosysteme.run();

   delete prev;
   delete greg;
   delete kami;
   delete peur;
   delete pers;

   return 0;

}
