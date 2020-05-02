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
#define MAX 100
#define MIN 0
enum StanjeCoveka{zdrav_covek, bolestan, mrtav};
enum polCoveka{muski, zenski,drugo};
bool porediMikroorganizme(vector<Mikroorganizam> m1, vector<Mikroorganizam>m2){
    if (m1.size()!= m2.size()){
        return false;
    }
    for (int i = 0 ; i < m1.size(); i ++){
        if (m1[i].getNaziv()!=m2[i].getNaziv()){
            return false;
        }
    }
    return true;
}
class Covek{
protected:
    int imunitet;
    string ime;
    string prezime;
    StanjeCoveka stanje;
    polCoveka pol;
    int godine;
    Organ ZarazenOrgan;
    Bolest bolest;
public :
    Covek(int imnt,string i, string p,StanjeCoveka s,int g, const Organ& zarorg,polCoveka pl ):  ZarazenOrgan(zarorg)
    {
        imunitet=imnt;
        ime=i;
        prezime=p;
        stanje=s;
        pol=pl;
        godine=g;
    }
    Covek(): ZarazenOrgan(), bolest() {imunitet=0; ime=" "; prezime=" "; stanje=zdrav_covek; godine=0; pol=drugo;}
    Covek(const Covek &c){imunitet=c.imunitet; ime=c.ime; prezime= c.prezime; stanje= c.stanje; pol= c.pol; godine= c.godine;  ZarazenOrgan=c.ZarazenOrgan;}
    
    void Zarazi(Bolest &b)
    {
        bolest=b;
        ZarazenOrgan=b.getOrgan();
        stanje=bolestan;
        cout<<ime<<" "<<prezime<<" ima "<<bolest.getNaziv()<<endl;
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
            cout<<" od "<<bolest.getNaziv()<<endl;
            
        }
        
    }
    void Izleci(Lek &l)
    {
        if (l.getTip()==vakcina)
        {
            cout<<ime<<" "<<prezime<<" je  vakcinisan";
            if (pol==zenski){
                cout<<"la";
            }
            cout<<" sa "<< l.getNaziv()<<endl;
        }
        else if (l.getTip()==pilula)
        {
            cout<<ime<<" "<<prezime<<" je uze";
            if (pol==zenski){
                cout<<"la";
            }
            else{
                cout<<" o";
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
                cout<<" o";
            }
            cout<<l.getNaziv()<<endl;
            
        }
        /*string getNaziv(){return naziv;}
        Organ getOrgan(){return NapadaOrgan;}
        int getNN(){return NivoNapadanja;}
        TipBolesti getTB(){return tip;}
        vector< Mikroorganizam>getMikroorganizam(){return izaziva;};*/
        if((l.getBolest()).getNaziv()==bolest.getNaziv()&&((l.getBolest()).getOrgan()).getIme()==(bolest.getOrgan()).getIme()&&((l.getBolest()).getOrgan()).getStanje()==(bolest.getOrgan()).getStanje()&&(l.getBolest()).getNN()==bolest.getNN()&&(l.getBolest()).getTB()==bolest.getTB()&&porediMikroorganizme(l.getBolest().getMikroorganizam(),bolest.getMikroorganizam())==true)
    
            
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
            
        }
        else
        {
            cout<<"Ovo ne leci ovu bolest"<<endl;
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
    
};

#endif /* covek_h */
