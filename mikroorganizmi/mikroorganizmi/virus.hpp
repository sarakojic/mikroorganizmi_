//
//  virus.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//
#ifndef virus_h
#define virus_h
#include "mikroorganizam.hpp"
class Virus:public Mikroorganizam{
protected:
    
    
public:
    Virus() :Mikroorganizam(){}
    Virus(string n ): Mikroorganizam(n){}
    Virus(const Virus & v):Mikroorganizam(v.naziv){}
    void ZaraziOrgan(  Organ & org)
          {
              cout<<"Virus ";
              Mikroorganizam::ZaraziOrgan(org);
          }
    friend ostream& operator<<(ostream& izlaz, const Virus& v)
    {
        izlaz<<"Virus - ispis"<<endl;
        izlaz<<"Naziv: "<<v.naziv<<endl<<endl;
        return izlaz;
    }
 
    
};

#endif /* virus_h */
