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
class VIRUS:public Mikroorganizam{
protected:
    
    
public:
    VIRUS() :Mikroorganizam(){}
    VIRUS(string n ): Mikroorganizam(n){}
    VIRUS(const Virus & v):Mikroorganizam(v.naziv){}
 
    
}

#endif /* virus_h */
