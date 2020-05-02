//
//  mesto.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef mesto_h
#define mesto_h
#include "zivotinja.hpp"
#include "covek.hpp"
class Mesto{
protected:
    string naziv;
    double povrsina;
    vector<Zivotinja> zivotinje;
    vector<Covek> ljudi;
    double gustina;
 
public:
    Mesto(){naziv=" "; povrsina=0; zivotinje.push_back(Zivotinja());ljudi.push_back(Covek());}
    Mesto(const Mesto &m){naziv=m.naziv; povrsina=m.povrsina; zivotinje=m.zivotinje; ljudi=m.ljudi; gustina=m.gustina;}

    
};


#endif /* mesto_h */
