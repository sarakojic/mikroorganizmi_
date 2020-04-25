//
//  organ.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef organ_h
#define organ_h
#include <iostream>
usingnamespace std;
enum stanje{zdrav, zarazen};
class ORGAN
{
protected:
    string ime;
    stanje StanjeOrgana;
    
public:
    ORGAN(string i=" "; stanje s= zdrav){ime=i;stanje=s;}
    ORGAN(const ORGAN& o){ime=o.ime; StanjeOrgana=o.StanjeOrgana;}
};




#endif /* organ_h */
