//
//  hrana.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef hrana_h
#define hrana_h
using namespace std;
class Hrana
{
protected:
    string ime;
    int NivoPovecanjaImuniteta;
    bool pojedena;
public:
    Hrana(string i= "Ova hrana je nepostojeca", int n= 0, int p= false){ime=i;NivoPovecanjaImuniteta=n;pojedena= p;}
    
};

#endif /* hrana_h */
