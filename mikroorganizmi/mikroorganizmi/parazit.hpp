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
enum vrsteParazita{ameba, bicar, trepljar, sporozoa}
class PARAZIT:public MIKROORGANIZAM{
protected:
    vrsteParazita tipParazita;
public:
    PARAZIT() :MIKROORGANIZAM(), tipParazita(ameba){}
    PARAZIT(string n; const BOLEST & b; vrsteParazita p ): MIKROORGANIZAM(n,b), tipParazita(p){}
    PARAZIT(const PARAZIT & p):MIKROORGANIZAM(p.naziv, p.bolest), p.tipParazita{}
   
}

#endif /* parazit_h */
