//
//  ZarazenOrgan.hpp
//  mikroorganizmi
//
//  Created by Sara on 5/15/20.
//  Copyright © 2020 Sara. All rights reserved.
//


#ifndef ZarazenOrgan_h
#define ZarazenOrgan_h
#include "organ.hpp"
#include "bolest.hpp"
#include <vector>
#include <iostream>
class ZarazenOrgan:public Organ
{
protected:
    vector<Bolest>bolesti ;
public:
    ZarazenOrgan(){ime=" "; stanje= zarazen; bolesti.push_back(Bolest());}
    ZarazenOrgan(string i, stanjeOrgana s, vector<Bolest> b)
    {
        ime=i;
        stanje=s;
        for(auto i=b.begin();i!=b.end();i++)
               bolesti.push_back(*i);
        
    }
    ZarazenOrgan( Organ & o, Bolest & b)
    {
        ime=o.getIme();
        bolesti.push_back(b);
        
    }
    friend ostream& operator<<(ostream& izlaz, const ZarazenOrgan& zo){
    izlaz<<"Zarazen Organ- ispis"<<endl;
    izlaz<<"Ime: "<<zo.ime<<endl;
    izlaz<<"Stanje organa: ";
    if(zo.stanje==0)
     {
         izlaz<<"zdrav"<<endl;
     }
     if(zo.stanje==1)
     {
         izlaz<<"zarazen"<<endl;
     }
    for (auto i=zo.bolesti.begin(); i !=zo.bolesti.end(); i ++)
        {
           izlaz<<*i;
        
        }
    izlaz<<endl;
        return izlaz;
        }
    


    
};

#endif /* ZarazenOrgan_h */
