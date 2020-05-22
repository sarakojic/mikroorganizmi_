//
//  zivotinja.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//


#ifndef zivotinja_h
#define zivotinja_h
#include "covek.hpp"

class Zivotinja
{
protected:
    string ime;
    string vrsta;
    bool slobodna;
    Covek vlasnik;
public:
    Zivotinja():ime(" "), slobodna(true), vlasnik(), vrsta(" ")
    {
        
    }
    Zivotinja(string i,string v, bool s,const Covek &c):ime(i), vrsta(v) ,slobodna(s),
    vlasnik(c)
    {
        
    }
    Zivotinja(const Zivotinja &z)
    {
        ime=z.ime;
        slobodna=z.slobodna;
        vlasnik=z.vlasnik;
        vrsta= z.vrsta;
        
    }
    

    
};

#endif /* zivotinja_h */
