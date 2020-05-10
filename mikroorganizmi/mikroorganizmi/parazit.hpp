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
    vrsteParazita tipParazita;
public:
    Parazit() :Mikroorganizam(), tipParazita(ameba){}
    Parazit(string n, vrsteParazita p ): Mikroorganizam(n), tipParazita(p){}
    Parazit(const Parazit & p):Mikroorganizam(p.naziv),tipParazita(p.tipParazita) {}
   friend ostream& operator<<(ostream& izlaz, const Parazit& p){
       izlaz<<"Parazit- ispis"<<endl;
       izlaz<<"Naziv: "<<p.naziv<<endl;
       izlaz<<"Vrsta parazita: ";
       if(p.tipParazita==0)
       {
           izlaz<<"ameba"<<endl;
       }
       if(p.tipParazita==1)
       {
           izlaz<<"bicar"<<endl;
       }
       if(p.tipParazita==2)
       {
           izlaz<<"trepljar"<<endl;
       }
       if(p.tipParazita==2)
       {
           izlaz<<"trepljar"<<endl;
       }
       if(p.tipParazita==3)
       {
           izlaz<<"sporozoa"<<endl;
       }
       izlaz<<endl;
       
     
   return izlaz;
   }
};

#endif /* parazit_h */
