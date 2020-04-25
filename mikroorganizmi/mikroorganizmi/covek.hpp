//
//  covek.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef covek_h
#define covek_h
#include "mesto.hpp"
#include "organ.hpp"
enum StanjeCoveka{zdrav, bolestan, mrtav};
enum polCoveka{muski, zenski};
class COVEK{
protected:
    int imunitet;
    string ime;
    string prezime;
    StanjeCoveka stanje;
  //  polCoveka pol;
    int godine;
    MESTO TrenutnaPozicija;
    ORGAN ZarazenOrgan
public :
  //  COVEK(int imnt=100,string i="Osoba", string p="Ne Postoji",StanjeCoveka s=zdrav,int g=0, MESTO& trenpoz, ORGAN& zarorg ): imunitet(imnt), ime(i), prezime(p), stanje(se), godine(g),TrentutnaPozicija(trenpoz), Zarazen Organ(zarorg) {}
}

#endif /* covek_h */
