//
//  lek.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.

#ifndef lek_h
#define lek_h
#include "bolest.hpp"
enum TipLeka{vakcina, pilula, operacija}
class LEK
{
protected:
    TipLeka tip;
    string naziv;
    int NivoDelotvornosti;
    BOLEST BolestKojuLeci;
public:
   // LEK(TipLeka t=pilula, string n= "nepostojeci lek", int nd= 0):BolestkojuLeci(){}


    
};

#endif /* lek_h */
