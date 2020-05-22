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

#include "mikroorganizam.hpp"



enum TipBolesti {bakterijska, virusna, parazitska,gljivicna};

class Bolest
{
protected:
    string naziv;
    int NivoNapadanja;
    TipBolesti tip;
    vector<Mikroorganizam*> izaziva;

public:
    void dodajM(Mikroorganizam* m)
    {
        izaziva.push_back(m);
    }
    Bolest():naziv(" "),NivoNapadanja(0), tip(virusna)
    {
        
    }

    Bolest(string n,int  nn,TipBolesti t, Mikroorganizam * m):
        naziv(n),  NivoNapadanja(nn), tip(t)
    {
        dodajM(m);
    }
    Bolest(string n,int  nn,TipBolesti t,vector< Mikroorganizam*>  m):
        naziv(n),  NivoNapadanja(nn), tip(t)
    {
        for (auto i=*m.begin(); i != *m.end(); i ++)
        {
            dodajM(i);

        }
    }
    Bolest(const Bolest &b)
    {
        naziv=b.naziv;
        tip=b.tip;
        izaziva=b.izaziva;
    }

    string getNaziv()
    {
        return naziv;
    }

    int getNN()
    {
        return NivoNapadanja;
    }
    TipBolesti getTB()
    {
        return tip;
    }
    vector< Mikroorganizam*>getMikroorganizam()
    {
        return izaziva;
    }
    void setNN(int x)
    {
        NivoNapadanja=x;
    }

    friend ostream& operator<<(ostream& izlaz, const Bolest& b)
    {
        izlaz<<"Bolest - ispis"<<endl;
        izlaz<<b.naziv<<endl;
        izlaz<<b.NivoNapadanja<<endl;
        izlaz<<b.tip<<endl;
        for (auto it=b.izaziva.begin(); it!=b.izaziva.end(); it++)
        {
            cout<<**it<<endl;
        }
        return izlaz;


    }
    void zarazi(Organ& o)
    {
        for (auto i=izaziva.begin(); i !=izaziva.end(); i++)
        {
            (*i)->ZaraziOrgan(o);

        }

    }

   ~Bolest()
    {
        izaziva.clear();
    }


};



#endif /* bolest_h */

