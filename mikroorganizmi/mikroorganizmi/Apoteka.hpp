//
//  Apoteka.hpp
//  mikroorganizmi
//
//  Created by Sara on 5/15/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef Apoteka_h
#define Apoteka_h
#include"mesto.hpp"
#include"lek.hpp"
#include"funkcije.h"
using namespace std;
class Apoteka: public Mesto
{
protected:
    vector<Lek> lekovi;
    
public:
    Apoteka():Mesto(){lekovi.push_back(Lek());}
    Apoteka(const Mesto & m, const Lek & l ): Mesto(m){lekovi.push_back(l);}
    Apoteka(string n, double p):Mesto(n,p){};
    void DodajLek(const Lek & l){lekovi.push_back(l);}
    void IspisiLekove()const
    {
        int x=1;
        for(auto i=lekovi.begin(); i!=lekovi.end(); i ++)
        {
            cout<<x<<"."<<(*i).getNaziv()<<" cena= "<< (*i).getCena()<<endl;
            x++;
        }
    }
    Lek KupiLek() const
    {

        clearscr();
        cout<<"__Dobrodosli u apoteku__"<<endl;
            cout<<"Izaberite lek: "<<endl;
            IspisiLekove();
            int lek;
            cin>>lek;
        return lekovi[lek-1];

        
    }
    void izbaciLek(string NazivLeka)
    {
        int x=0;
        for (auto i = lekovi.begin(); i != lekovi.end(); i ++)
        {
    
            if ((*i).getNaziv()==NazivLeka)
            {
               lekovi.erase(i);
                
            }
            x++;
            
        }
    }
    void dodajCoveka(const Covek & c){ljudi.push_back(c);}
    int TipMesta(){return 2;}

};

#endif /* Apoteka_h */