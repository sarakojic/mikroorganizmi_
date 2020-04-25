//
//  mikroorganizam.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/25/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef mikroorganizam_h
#define mikroorganizam_h
#include "bolest.hpp"
class MIKROORGANIZAM{
protected:
    string naziv;
    BOLEST bolest;
    
public:
    MIKROORGANIZAM(string n, const BOLEST&b): naziv(n), bolest(b){}
    MIKROORGANIZAM(): naziv(" "), bolest(){}
    MIKROORGANIZAM(const MIKROORGANIZAM & m){naziv=m.naziv;bolest=m.bolest;}
    
};

#endif /* mikroorganizam_h */
