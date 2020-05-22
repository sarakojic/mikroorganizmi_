//
//  hrana.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//


#ifndef hrana_h
#define hrana_h

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
    friend ostream& operator<<(ostream& izlaz, const Hrana& h)
        {
            izlaz<<"Hrana- ispis"<<endl;
            izlaz<<"Ime : "<<h.ime<<endl;
            izlaz<<"Nivo povecanja imuniteta : "<<h.NivoPovecanjaImuniteta<<endl;
            if (h.pojedena)
            {
            izlaz<<"Hrana je pojedena"<<endl;
            }
            else
            {
            izlaz<<"Hrana nije pojedena"<<endl;

            }
            izlaz<<"Cena: "<<h.cena<<endl;
            return izlaz;
            
        }

};

#endif /* hrana_h */
