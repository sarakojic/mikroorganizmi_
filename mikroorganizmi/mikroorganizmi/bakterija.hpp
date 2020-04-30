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
enum OblikBakterije{koka, bacil, spiril}
class Bakterija:public Mikroorganizam{
protected:
    OblikBakterije bakterija;

public:
    Bakterija() :Mikroorganizam(), bakterija(koka){}
     Bakterija(string n, OblikBakterije o ): Mikroorganizam(n), bakterija(o){}
     Bakterija(const Bakterija & b):Mikroorganizam(b.naziv), bakterija(b.bakterija){}
    
}


#endif /* bakterija_h */
