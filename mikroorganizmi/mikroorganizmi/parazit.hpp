//
//  parazit.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef parazit_h
#define parazit_h
#include "mikroorganizam.hpp"
enum vrsteParazita{ameba, bicar, trepljar, sporozoa};
class Parazit:public Mikroorganizam{
protected:
    vrsteParazita vrsta;
public:
    Parazit() :Mikroorganizam(), vrsta(ameba){}
    Parazit(string n, vrsteParazita p ): Mikroorganizam(n), vrsta(p){}
    Parazit(const Parazit & p):Mikroorganizam(p.naziv),vrsta(p.vrsta) {}
    vrsteParazita getVrsta(){return vrsta;}
   friend ostream& operator<<(ostream& izlaz, const Parazit& p){
       izlaz<<"Parazit- ispis"<<endl;
       izlaz<<"Naziv: "<<p.naziv<<endl;
       izlaz<<"Vrsta parazita: ";
       if(p.vrsta==0)
       {
           izlaz<<"ameba"<<endl;
       }
       if(p.vrsta==1)
       {
           izlaz<<"bicar"<<endl;
       }
       if(p.vrsta==2)
       {
           izlaz<<"trepljar"<<endl;
       }
       if(p.vrsta==2)
       {
           izlaz<<"trepljar"<<endl;
       }
       if(p.vrsta==3)
       {
           izlaz<<"sporozoa"<<endl;
       }
       izlaz<<endl;
       
     
   return izlaz;
   }
    void ZaraziOrgan(  Organ & org)
    {
        cout<<"Parazit koji je ";
        if(vrsta==0)
        {
            cout<<"ameba";
        }
        if(vrsta==1)
        {
            cout<<"bicar";
        }
        if(vrsta==2)
        {
            cout<<"trepljar";
        }
        if(vrsta==2)
        {
            cout<<"trepljar";
        }
        if(vrsta==3)
        {
            cout<<"sporozoa";
        }
        cout<<" i zove se ";
        Mikroorganizam::ZaraziOrgan(org);
    }
};

#endif /* parazit_h */
