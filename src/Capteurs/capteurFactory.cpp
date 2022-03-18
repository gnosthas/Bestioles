#ifndef CAPTEURFACTORY
#define CAPTEURFACTORY

#include <iostream>
using namespace std;

#include "capteur.h"
#include "yeux.h"
#include "corps.h"
#include "oreilles.h"

enum TypeCapteur{
    TC_Yeux, TC_Oreilles, TC_Corps
};

class CapteurFactory {
    public:
        ~CapteurFactory(){cout<<"Destruction capteur factory"<<endl;};
        static ICapteur* createCapteur(TypeCapteur type, int id);
};

ICapteur* createCapteur(TypeCapteur type, int id){
        if(type == TC_Yeux){
            return new Yeux();
        } else if (type == TC_Oreilles) {
            return new Oreilles();
        } else if (type == TC_Corps) {
            return new Corps();
        } else return NULL;

}



#endif


