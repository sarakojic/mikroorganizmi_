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
class POTPREN{
protected:
    string naziv;
    bool prenosnik;
    PARAZIT NosiParazit;
public:
    POTPREN(string n="Potencijalni prenosnik ne postoji", bool p=false, PARAZIT& par):naziv(n), prenosnik(p),NosiParazit(par){}
    
    
};


#endif /* PotencijalniPrenosnik_h */
