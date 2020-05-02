//
//  bolest.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef bolest_h
#define bolest_h
#include <iostream>
#include "organ.hpp"
#include "mikroorganizam.hpp"
using namespace std;

enum TipBolesti{bakterijska, virusna, parazitska};

class Bolest{
protected:
    string naziv;
    Organ NapadaOrgan;
    int NivoNapadanja;
    TipBolesti tip;
    vector<Mikroorganizam> izaziva;
    
public:
    Bolest():naziv(" "), NapadaOrgan(),NivoNapadanja(0), tip(virusna){izaziva.push_back(Mikroorganizam());}
    
    Bolest(string n,const Organ& no,int  nn,TipBolesti t ,const Mikroorganizam & m):
    naziv(n), NapadaOrgan(no), NivoNapadanja(nn), tip(t)
    {
        izaziva.push_back(Mikroorganizam(m));
    }
    Bolest(const Bolest &b)
       {
           naziv=b.naziv;
           NapadaOrgan=b.NapadaOrgan;
           tip=b.tip;
           izaziva=b.izaziva;
       }

    string getNaziv(){return naziv;}
    Organ getOrgan(){return NapadaOrgan;}
    int getNN(){return NivoNapadanja;}
    TipBolesti getTB(){return tip;}
    vector< Mikroorganizam>getMikroorganizam(){return izaziva;}

};


#endif /* bolest_h */
