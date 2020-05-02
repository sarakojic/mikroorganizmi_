//
//  lek.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.

#ifndef lek_h
#define lek_h
#include "bolest.hpp"
enum TipLeka{vakcina, pilula, operacija};
class Lek
{
protected:
    TipLeka tip;
    string naziv;
    int NivoDelotvornosti;
    Bolest BolestKojuLeci;
public:
    Lek(): tip(pilula), naziv(" "), NivoDelotvornosti(0),BolestKojuLeci(){}
    Lek(TipLeka t, string n, int nd,const Bolest &b): tip(t), naziv(n), NivoDelotvornosti(nd),BolestKojuLeci(b){}
    Lek(const Lek &l)
    {
        tip=l.tip;
        naziv=l.naziv;
        NivoDelotvornosti=l.NivoDelotvornosti;
        BolestKojuLeci=l.BolestKojuLeci;
        
    }
    TipLeka getTip()
    {
        return tip;
    }
    Bolest getBolest()
    {
        return BolestKojuLeci;
    }
    string getNaziv()
    {
        return naziv;
    }
    int getND()
    {
        return NivoDelotvornosti;
    }


    
};  
#endif /* lek_h */
