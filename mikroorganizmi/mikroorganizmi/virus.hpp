//
//  virus.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef virus_h
#define virus_h
#include "mikroorganizam.hpp"
class VIRUS:public MIKROORGANIZAM{
protected:
    
    
public:
    VIRUS() :MIKROORGANIZAM(){}
    VIRUS(string n; const BOLEST & b; ): MIKROORGANIZAM(n,b){}
    VIRUS(const BAKTERIJA & b):MIKROORGANIZAM(b.naziv, b.bolest){}
 
    
}

#endif /* virus_h */
