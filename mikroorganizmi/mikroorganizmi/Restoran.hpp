//
//  Restoran.hpp
//  mikroorganizmi
//
//  Created by Sara on 5/15/20.
//  Copyright © 2020 Sara. All rights reserved.
//


#ifndef Restoran_h
#define Restoran_h
#include"mesto.hpp"
#include"hrana.hpp"
#include"funkcije.h"

class Restoran: public Mesto
{
protected:
    vector<Hrana> jelovnik;
public:
    Restoran(): Mesto(){ jelovnik.push_back(Hrana());}
    Restoran(const Mesto & m, const Hrana & h):Mesto(m){ jelovnik.push_back(Hrana(h));}
    void dodajHranu(Hrana h){jelovnik.push_back(h);}
    void VidiJelovnik()
    {
        int x=1;
        for(auto i=jelovnik.begin(); i !=jelovnik.end(); i ++)
        {
            cout<<x<<"."<<(*i).getIme()<<", "<<"cena= "<<(*i).getCena()<<endl;
            x++;
        }
        
    }
    Restoran(string n, double p):Mesto(n,p){}
    string naziv;
     double povrsina;
     vector<Covek> ljudi;
    Hrana Naruci()
    {
        clearscr();
        cout<<"__Pogledajte Jela__"<<endl;
        usleep(4000000);
        VidiJelovnik();
        cout<<"Koji je broj vaseg jela ?"<<endl;
        int a;
        cin>>a;
        clearscr();
        cout<<"Molimo vas sacekajte vase jelo ce uskoro biti pripremljeno"<<endl;
        usleep(4000000);
        cout<<"Vase jelo je pripremljeno"<<endl;
        return jelovnik[a-1];
    }
    
    void dodajCoveka(const Covek & c)
    {
        Mesto::dodajCoveka(c);
        
    }
    void izadji(Covek & c)
    {
        cout<<c.getIme()<<" "<< c.getPrezime()<<" je izas";
        if (c.getPol()==zenski)
        {
            cout<<"la";
        }
        else
        {
            cout<<"ao";
        }
        cout<<" iz "<<naziv;
        for (auto i = ljudi.begin(); i!= ljudi.end(); i ++)
        {
            if (c.getIme()==(*i).getIme()&&c.getPrezime()==(*i).getPrezime())
            {
                ljudi.erase(i);
            }
        }

        
    }
 
    void IzbaciJelo(string naziv)
    {
        for (auto i= jelovnik.begin(); i != jelovnik.end(); i ++)
        {
            if ((*i).getIme()==naziv)
            {
                cout<<naziv<<" ce biti uklonjen sa jelovnika"<<endl;
                jelovnik.erase(i);
            }
        }
    }
    double GustinaMesta()
    {
        return Mesto::GustinaMesta();
    }
};


#endif /* Restoran_h */
