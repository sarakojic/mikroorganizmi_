//
//  bakterija.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef bakterija_h
#define bakterija_h
#include "mikroorganizam.hpp"
enum OblikBakterije(koka,bacil, spiril)
class BAKTERIJA:public MIKROORGANIZAM{
protected:
    OblikBakterije bakterija;

public:
    BAKTERIJA() :MIKROORGANIZAM(), bakterija(koka){}
     BAKTERIJA(string n, const BOLEST & b, OblikBakterije o ): MIKROORGANIZAM(n,b), bakterija(o){}
     BAKTERIJA(const BAKTERIJA & b):MIKROORGANIZAM(b.naziv, b.bolest), bakterija(b.bakterija){}
    
}


#endif /* bakterija_h */
