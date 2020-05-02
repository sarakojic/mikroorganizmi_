//
//  PotencijalniPrenosnik.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef PotencijalniPrenosnik_h
#define PotencijalniPrenosnik_h
#include "parazit.hpp"
using namespace std;
class Potpren{
protected:
    string naziv;
    bool prenosnik;
    Parazit NosiParazit;
public:
    Potpren(string n, bool p, const Parazit& par):naziv(n), prenosnik(p),NosiParazit(par){}
    Potpren():naziv(" "), prenosnik(false),NosiParazit(){}
    Potpren(const Potpren &pp){naziv=pp.naziv; prenosnik=pp.prenosnik; NosiParazit=pp.NosiParazit;}
    
    
};


#endif /* PotencijalniPrenosnik_h */
