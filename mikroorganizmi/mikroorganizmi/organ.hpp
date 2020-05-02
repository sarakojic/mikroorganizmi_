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
using namespace std;
enum stanje{zdrav, zarazen};
class Organ
{
protected:
    string ime;
    stanje StanjeOrgana;
    
public:
    Organ(string i=" ", stanje s= zdrav){ime=i;StanjeOrgana=s;}
    Organ(const Organ& o){ime=o.ime; StanjeOrgana=o.StanjeOrgana;}
    string getIme(){return ime;}
    stanje getStanje(){return StanjeOrgana;}
};




#endif /* organ_h */
