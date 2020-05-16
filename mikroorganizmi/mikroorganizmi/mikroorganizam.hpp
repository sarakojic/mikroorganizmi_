//
//  mikroorganizam.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/25/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef mikroorganizam_h
#define mikroorganizam_h
#include <iostream>
using namespace std;
#include "organ.hpp"
using namespace std;
class Mikroorganizam
{
protected:
    string naziv;
    static int brojM;

    
public:
    Mikroorganizam(string n): naziv(n){brojM++;}
    Mikroorganizam(): naziv(" "){brojM++;}
    Mikroorganizam(const Mikroorganizam & m){naziv=m.naziv;brojM++;}
    string getNaziv(){return naziv;}
    static int getBroj(){return brojM;}

    friend ostream& operator<<(ostream& izlaz, const Mikroorganizam& m);
    ~Mikroorganizam(){
           brojM--;
       }
    virtual void ZaraziOrgan(  Organ & org)
    {
        org.setStanje(zarazen);
        cout<<naziv<<" je zarazio "<< org.getIme()<<endl;
    }
    
    
    
};
ostream& operator<<(ostream& izlaz, const Mikroorganizam& m){
    izlaz<<"Mikrooranizam - ispis"<<endl;
    izlaz<<"Naziv: "<<m.naziv<<endl<<endl;

  
return izlaz;
}


#endif /* mikroorganizam_h */
