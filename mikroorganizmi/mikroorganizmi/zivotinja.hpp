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
    bool slobodna;
    Covek vlasnik;
public:
    Zivotinja():ime(" "), slobodna(true), vlasnik(){}
    Zivotinja(string i, bool s,const Covek &v):ime(i), slobodna(s),
    vlasnik(v){}

    
};

#endif /* zivotinja_h */
