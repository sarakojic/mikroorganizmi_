//
//  covek.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef covek_h
#define covek_h
#include "mesto.hpp"
#include "organ.hpp"
#include "bolest.hpp"
#include "lek.hpp"
#define MAX 100
#define MIN 0
enum StanjeCoveka{zdrav, bolestan, mrtav};
enum polCoveka{muski, zenski,drugo};
class Covek{
protected:
    int imunitet;
    string ime;
    string prezime;
    StanjeCoveka stanje;
    polCoveka pol;
    int godine;
    Mesto TrenutnaPozicija;
    Organ ZarazenOrgan;
    Bolest bolest;
public :
    Covek(int imnt,string i, string p,StanjeCoveka s,int g,const Mesto& trenpoz, const Organ& zarorg,polCoveka pl ): imunitet(imnt), ime(i), prezime(p), stanje(se), godine(g),TrentutnaPozicija(trenpoz), Zarazen Organ(zarorg), pol(pl) {}
     Covek( ): imunitet(0), ime(" "), prezime(" "), stanje(zdrav), godine(0),TrentutnaPozicija(), ZarazenOrgan(), bolest(),pol(drugo) {}
    
    void Zarazi(Bolest b)
    {
        bolest=b;//kad budemo radili vektore napravicu da moze da postoji vektor bolesti tako da cu tad izmeniti ovo ali za sada cu ovako da napisem(isto vazi i za organe)
        ZarazenOrgan=b.getOrgan();
        stanje=bolestan;
        cout<<ime<<" "<<prezime<<" ima "<<bolest.getNaziv()<<endl
        if (imunitet- b.getNN>=MIN)
        {
        imunitet= imunitet- b.getNN;
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
    void Izleci(Lek l)
    {
        if (l.getTip()==vakcina)
        {
            cout<<ime<<" "<<prezime<<" je  vakcinisan";
            if (pol=zensko){
                cout<<"la";
            }
            cout<<" sa "<< l.getNaziv()<<endl;
        }
        else if (l.getTip()==pilula)
        {
            cout<<ime<<" "<<prezime<<" je uze";
            if (pol=zensko){
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
            if (pol=zensko){
                cout<<"la";
            }
            else{
                cout<<" o";
            }
            cout<<l.getNaziv()<<endl;
            
        }
        if(l.getBolest()==bolest)
        {
            if (imunitet+ l.getND()<=MAX)
            {
                imunitet+= l.getND();
            }
            else
            {
                imunitet= 100;
                stanje=zdrav;
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
    
}

#endif /* covek_h */
