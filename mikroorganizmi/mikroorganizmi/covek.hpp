//
//  covek.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef covek_h
#define covek_h
#include "organ.hpp"
#include "bolest.hpp"
#include "lek.hpp"
#include "mikroorganizam.hpp"
#include "ZarazenOrgan.hpp"
#include "hrana.hpp"




#define MAX 100
#define MIN 0

enum StanjeCoveka{zdrav_covek, bolestan, mrtav};
enum polCoveka{muski, zenski,drugo};

bool porediMikroorganizme(vector<Mikroorganizam*> m1, vector<Mikroorganizam*>m2){
    if (m1.size()!= m2.size()){
        return false;
    }
    for (int i = 0 ; i < m1.size(); i ++){
        if ((m1[i])->getNaziv()!=m2[i]->getNaziv()){
            return false;
        }
    }
    return true;
}

ZarazenOrgan ZaraziOrg(Organ & o,Bolest & b){
for (auto i=(b.getMikroorganizam()).begin(); i !=(b.getMikroorganizam()).end(); i ++)
{
      (*i)->ZaraziOrgan(o);
    
}
    ZarazenOrgan zo(o,b) ;
    
    return zo;
}

class Covek{
protected:
    int imunitet;
    string ime;
    string prezime;
    StanjeCoveka stanje;
    polCoveka pol;
    int godine;
    vector<ZarazenOrgan> zo;
    vector<Bolest>bolest;
    vector<Organ>organ;
    int novac;

public :
    Covek(int imnt,string i, string p,StanjeCoveka s,int g,polCoveka pl,int n )  {imunitet=imnt;ime=i;prezime=p;stanje=s;pol=pl;godine=g;novac=n;}
    Covek():zo(),bolest(), organ(){imunitet=0; ime=" "; prezime=" "; stanje=zdrav_covek; godine=0; pol=drugo;novac=0;}
    Covek(const Covek &c){imunitet=c.imunitet; ime=c.ime; prezime= c.prezime; stanje= c.stanje; pol= c.pol; godine= c.godine; zo=c.zo;bolest=c.bolest;organ=c.organ;novac=c.novac;}
    string getIme()const{return ime;}
    string getPrezime()const{return prezime;}
    
    void Zarazi(Bolest &b, Organ &o)
    {
        bolest.push_back(b);
        zo.push_back(ZaraziOrg(o,b));
        stanje=bolestan;
        cout<<ime<<" "<<prezime<<" ima "<<b.getNaziv()<<endl;
        if (imunitet- b.getNN()>=MIN)
        {
            imunitet= imunitet- b.getNN();
        }
        else
        {
            stanje=mrtav;
            cout<<ime<<" "<<prezime<<" je nazalost"<<" preminu";
            if (pol==zenski)
            {
                cout<<"la";
            }
            else
            {
                cout<<"o";
            }
            cout<<" od ";
            for(auto i=bolest.begin(); i!=bolest.end(); i++)
            {
                cout<<(*i).getNaziv()<<" ";
            }
            cout<<endl;
            
            
        }
        
    }
    void Izleci(const Lek &l)
    {
        if (novac-l.getCena()>=0)
        {
            cout<<"potroseno "<<l.getCena()<<" od "<<novac<<endl;
    
        }
        if (novac-l.getCena()<0)
        {
            cout<<ime<<" "<<prezime<< " nema dovoljno para da plati ovaj lek"<<endl;
            return;
            
        }
        if (l.getTip()==vakcina)
        {
            cout<<ime<<" "<<prezime<<" je vakcinisan";
            if (pol==zenski){
                cout<<"la";
            }
            cout<<" sa "<< l.getNaziv()<<endl;
        }
        else if (l.getTip()==pilula)
        {
            cout<<ime<<" "<<prezime<<" je uze";
            if (pol==zenski){
                cout<<"la ";
            }
            else{
                cout<<"o ";
            }
            cout<<l.getNaziv()<<endl;
        }
        else  if (l.getTip()==operacija)
        {
            cout<<ime<<" "<<prezime<<" ima";
            if (pol==zenski){
                cout<<"la";
            }
            else{
                cout<<"o";
            }
            cout<<l.getNaziv()<<endl;
            
        }
        int x=1;
        for (auto i = bolest.begin(); i!=bolest.end(); i ++)
        { if((l.getBolest()).getNaziv()==(*i).getNaziv()&&(l.getBolest()).getNN()==(*i).getNN()&&(l.getBolest()).getTB()==(*i).getTB()&&porediMikroorganizme(l.getBolest().getMikroorganizam(),(*i).getMikroorganizam())==true)
            {
                if (imunitet+ l.getND()<=MAX)
                {
                    imunitet+= l.getND();
                }
                else
                {
                    imunitet= 100;
                    stanje=zdrav_covek;
                }
                break;
                
            }
            x++;
            
            
        }
        if (x==bolest.size())
        {
            cout<<"Ovo ne leci ni jednu bolest od "<<ime<<" "<<prezime<<endl;
            return;
        }
        if (bolest[x].getNN()-l.getND()>=0)
        {
            bolest[x].setNN(bolest[x].getNN()-l.getND());

        }
        if (bolest[x].getNN()-l.getND()<0){bolest[x].setNN(0);}
        if (bolest[x].getNN()==0)
        {
            for (auto i = bolest.begin(); i != bolest.end(); i ++)
            {
                if ((*i).getNaziv()==bolest[x].getNaziv())
                    bolest.erase(i);
                
            }
    
        }
        
        if (imunitet==100)
        {
            cout<<"!!!!"<<ime<<" " <<prezime<< " je "<<"izlecen";
            if (pol==zenski)
            {
                cout<<"a!!!!"<<endl;
            }
            else
            {
                cout<<"!!!!"<<endl;
            }
            
        }
        
        
    }


    void pojedi(Hrana h)
    {
        if (h.getPojedena()==false)
        {
        
            if (imunitet+ h.getNPI()<=MAX)
            {
                imunitet+=h.getNPI();
            }
            else
            {
                imunitet=MAX;
            }
            
        }
        if (novac-h.getCena()>=0)
        {
            cout<<"potroseno je "<< h.getCena()<< " od "<<novac<<endl;
            novac-=h.getCena();
            
        }
        else
        {
            cout<<ime<<" "<< prezime<< " nema dovoljno para da plati ovo"<<endl;
            return;
        }
        usleep(2000000);
        cout<<ime<<prezime<<" je poje";
        if (pol==zenski){cout<<"la ";}
        else{cout<<"o ";}
        cout<<h.getIme()<<endl;
        
    }
    polCoveka getPol()const{return pol;}
    StanjeCoveka getStanje()const{return stanje;}
    int GetBrojBolesti()const{return(int) bolest.size();}
    vector<Bolest> GetBolesti()const{return bolest;}
    vector<ZarazenOrgan> GetZO()const{return zo;}
   

};

#endif /* covek_h */
