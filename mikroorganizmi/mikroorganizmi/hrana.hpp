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
    int cena;
public:
    Hrana(string i= "Ova hrana je nepostojeca", int n= 0, int p= false, int c=0)
    {
        ime=i;
        NivoPovecanjaImuniteta=n;
        pojedena= p;
        cena=c;
        
    }
    Hrana(const Hrana &h)
    {
        ime=h.ime;
        NivoPovecanjaImuniteta=h.NivoPovecanjaImuniteta;
        pojedena= h.pojedena;
        cena=h.cena;
        
    }
    string getIme(){return ime;}
    int getNPI(){return NivoPovecanjaImuniteta;}
    void setPojedena(bool p){pojedena=p;}
    bool getPojedena(){return pojedena;}
    int getCena(){return cena;}

};

#endif /* hrana_h */
