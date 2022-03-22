#include <iostream>
using namespace std;

#include "capteurFactory.h"
#include "capteur.h"
#include "yeux.h"
#include "corps.h"
#include "oreilles.h"


ICapteur* createCapteur(TypeCapteur type){
        if(type == TC_Yeux){
            return new Yeux();
        } else if (type == TC_Oreilles) {
            return new Oreilles();
        } else if (type == TC_Corps) {
            return new Corps();
        } else return NULL;

}
