//
//  gljive.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//


#ifndef gljive_h
#define gljive_h
#include "mikroorganizam.hpp"
enum vrstaGljive{plesni, pecurke, kvasci};
class Gljiva:public Mikroorganizam{
protected:
    vrstaGljive vrsta;
public:
    Gljiva() :Mikroorganizam(), vrsta(plesni)
    {
        
    }
    Gljiva(string n, vrstaGljive v) :Mikroorganizam(n), vrsta(v)
    {
        
    }
    Gljiva(const Gljiva & g ) :Mikroorganizam(g.naziv), vrsta(g.vrsta)
    {
        
    }
    void ZaraziOrgan(  Organ & org)
          {
              cout<<"Gljiva koja je ";
              if(vrsta==0)
              {
                  cout<<"plesan";
              }
              if(vrsta==1)
              {
                  cout<<"pecurka";
              }
              if(vrsta==2)
              {
                  cout<<"kvasac";
              }
              cout<<" i zove se ";
              Mikroorganizam::ZaraziOrgan(org);
          }
    friend ostream& operator<<(ostream& izlaz, const Gljiva& g)
    {
    izlaz<<"Gljiva- ispis"<<endl;
    izlaz<<"Naziv: "<<g.naziv<<endl;
    izlaz<<"Vrsta je: ";
    if(g.vrsta==0)
        {
            izlaz<<"plesan";
        }
        if(g.vrsta==1)
        {
            izlaz<<"pecurka";
        }
        if(g.vrsta==2)
        {
            izlaz<<"kvasac";
        }
        
    izlaz<<endl;
        return izlaz;
    }
    
    
};


#endif /* gljive_h */
