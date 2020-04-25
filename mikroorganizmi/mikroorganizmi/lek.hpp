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
class Lek
{
protected:
    TipLeka tip;
    string naziv;
    int NivoDelotvornosti;
    Bolest BolestKojuLeci;
public:
    Lek(TipLeka t=pilula, string n= "nepostojeci lek", int nd= 0): tip(t), naziv(n), NivoDelotvornosti(nd),BolestkojuLeci(){}


    
};

#endif /* lek_h */
