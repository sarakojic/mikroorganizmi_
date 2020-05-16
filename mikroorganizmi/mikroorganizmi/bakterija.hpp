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
    OblikBakterije oblik;

public:
    Bakterija() :Mikroorganizam(), oblik(koka){}
    Bakterija(string n, OblikBakterije o ): Mikroorganizam(n), oblik(o){}
    Bakterija(const Bakterija & b):Mikroorganizam(b.naziv), oblik(b.oblik){}
    
    void ZaraziOrgan(  Organ & org)
       {
           cout<<"Bakterija koja je ";
           if(oblik==0)
           {
               cout<<"koka";
           }
           if(oblik==1)
           {
               cout<<"bacil";
           }
           if(oblik==2)
           {
               cout<<"spiril";
           }
           cout<<" i zove se ";
           Mikroorganizam::ZaraziOrgan(org);
       }
    
     friend ostream& operator<<(ostream& izlaz, const Bakterija& b){
         izlaz<<"Bakterija- ispis"<<endl;
         izlaz<<"Naziv: "<<b.naziv<<endl;
         izlaz<<"Oblik Bakterije: ";
         if(b.oblik==0)
          {
              izlaz<<"koka"<<endl;
          }
          if(b.oblik==1)
          {
              izlaz<<"bacil"<<endl;
          }
          if(b.oblik==2)
          {
              izlaz<<"spiril"<<endl;
          }
         izlaz<<endl;
     return izlaz;
     }
    
};

#endif /* bakterija_h */
