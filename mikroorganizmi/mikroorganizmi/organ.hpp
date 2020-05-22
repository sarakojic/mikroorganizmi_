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

enum stanjeOrgana{zdrav,zarazen};
class Organ
{
protected:
    string ime;
    stanjeOrgana stanje;
    
public:
    Organ(string i=" ", stanjeOrgana s= zdrav){ime=i;stanje=s;}
    Organ(const Organ& o){ime=o.ime; stanje=o.stanje;}
    string getIme(){return ime;}
    stanjeOrgana getStanje(){return stanje;}
    friend ostream& operator<<(ostream& izlaz, const Organ& o)
    {
        izlaz<<"Organ- ispis"<<endl;
        izlaz<<"Ime: "<<o.ime<<endl;
        izlaz<<"Stanje organa: ";
        if(o.stanje==0)
         {
             izlaz<<"zdrav"<<endl;
         }
         if(o.stanje==1)
         {
             izlaz<<"zarazen"<<endl;
         }
        izlaz<<endl;
      
    return izlaz;
    }
    void setStanje( stanjeOrgana st)
    {
        stanje = st;
    }

};



#endif /* organ_h */
