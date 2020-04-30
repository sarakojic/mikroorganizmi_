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
usingnamespace std;
enum TipBolesti{bakterijska, virusna, parazitska};

class Bolest{
protected:
    string naziv;
    Organ NapadaOrgan;
    int NivoNapadanja;
    TipBolesti tip;
    Mikroorganizam izaziva[20];
    
public:
    Bolest():naziv(" "), NapadaOrgan(),NivoNapadanja(0), TipBolesti(virusna){Izaziva[0]=Mikroorganizam();}
    Bolest(string n,const Organ& no,int  nn,TipBolesti t , Mikroorganizam m[]): naziv(n), NapadaOrgan(no), NivoNapadanja(nn), TipBolest(t), izaziva(m){}
    string getNaziv(){return naziv;}
    Organ getOrgan(){return NapadaOrgan;}
    int getNN(){return NivoNapadanja;}
    TipBolesti getTB(){return tip;}
    Mikroorganizam getNaziv(){return izaziva;}

}


#endif /* bolest_h */
