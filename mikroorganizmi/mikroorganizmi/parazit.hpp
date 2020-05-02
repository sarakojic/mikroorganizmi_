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
   
};

#endif /* parazit_h */
