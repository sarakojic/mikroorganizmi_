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
    int cena;
public:
    Lek(): tip(pilula), naziv(" "), NivoDelotvornosti(0),BolestKojuLeci(), cena(0){}
    Lek(TipLeka t, string n, int nd,const Bolest &b, int c): tip(t), naziv(n), NivoDelotvornosti(nd),BolestKojuLeci(b), cena(c){}
Lek(const Lek& l
    ){tip=l.tip;naziv=l.naziv;NivoDelotvornosti=l.NivoDelotvornosti;BolestKojuLeci=l.BolestKojuLeci;cena=l.cena;}
    
    TipLeka getTip() const
    {
        return tip;
    }
    Bolest getBolest() const
    {
        return BolestKojuLeci;
    }
    string getNaziv()const
    {
        return naziv;
    }
    int getND()const
    {
        return NivoDelotvornosti;
    }
    int getCena() const
    {
        return cena;
    }
   


    
};  
#endif /* lek_h */
