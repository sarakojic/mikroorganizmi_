//
//  bakterija.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef bakterija_h
#define bakterija_h
#include "mikroorganizam.hpp"
enum OblikBakterije{koka, bacil, spiril};
class Bakterija:public Mikroorganizam{
protected:
    OblikBakterije bakterija;

public:
    Bakterija() :Mikroorganizam(), bakterija(koka){}
     Bakterija(string n, OblikBakterije o ): Mikroorganizam(n), bakterija(o){}
     Bakterija(const Bakterija & b):Mikroorganizam(b.naziv), bakterija(b.bakterija){}
     friend ostream& operator<<(ostream& izlaz, const Bakterija& b){
         izlaz<<"Bakterija- ispis"<<endl;
         izlaz<<"Naziv: "<<b.naziv<<endl;
         izlaz<<"Oblik Bakterije: ";
         if(b.bakterija==0)
          {
              izlaz<<"koka"<<endl;
          }
          if(b.bakterija==1)
          {
              izlaz<<"bacil"<<endl;
          }
          if(b.bakterija==2)
          {
              izlaz<<"spiril"<<endl;
          }
         izlaz<<endl;
     return izlaz;
     }
};

#endif /* bakterija_h */
