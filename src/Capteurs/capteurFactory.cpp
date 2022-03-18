#include "capteurFactory.h"
#include "yeux.h"
#include "corps.h"
#include "oreilles.h"

ICapteur* CapteurFactory::createCapteur(TypeCapteur type, int id){
        if(type == TC_Yeux){
            return new Yeux();
        } else if (type = TC_Oreilles) {
            return new Oreilles();
        } else if (type = TC_Corps) {
            return new Corps();
        } else return NULL;

};


