#include <iostream>
using namespace std;

#include "capteurFactory.h"
#include "capteur.h"
#include "yeux.h"
#include "corps.h"
#include "oreilles.h"


ICapteur* CapteurFactory::createCapteur(TypeCapteur type){
        if(type == TC_Yeux){
            cout << "Creation Yeux" << endl;
            return new Yeux();
        } else if (type == TC_Oreilles) {
            cout << "Creation Oreilles" << endl;
            return new Oreilles();
        } else if (type == TC_Corps) {
            cout << "Creation Corps" << endl;
            return new Corps();
        } else return NULL;

}
