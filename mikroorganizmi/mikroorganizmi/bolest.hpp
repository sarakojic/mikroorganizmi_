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
usingnamespace std;
enum TipBolesti(bakterijska, virusna, parazitska);

class BOLEST{
protected:
    string naziv;
    ORGAN NapadaOrgan;
    int NivoNapadanja;
    TipBolesti tip;
public:
    BOLEST():naziv(" "), NapadaOrgan(),NivoNapadanja(0), TipBolesti(virusna){}
    BOLEST(string n,const ORGAN& no,int  nn,TipBolesti t ): naziv(n), NapadaOrgan(no), NivoNapadanja(nn), TipBolest(t){}
 
    
}


#endif /* bolest_h */
