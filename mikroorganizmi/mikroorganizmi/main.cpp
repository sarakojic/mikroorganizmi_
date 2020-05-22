//
//  main.cpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#include <iostream>

#include <vector>
#include <fstream>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

#include "PotencijalniPrenosnik.hpp"
#include "hrana.hpp"
#include "bakterija.hpp"
#include "virus.hpp"
#include "bolest.hpp"
#include "parazit.hpp"
#include "mikroorganizam.hpp"
#include "organ.hpp"
#include "covek.hpp"
#include "gljive.hpp"
#include "zivotinja.hpp"
#include "lek.hpp"
#include "mesto.hpp"
#include "ZarazenOrgan.hpp"
#include "Restoran.hpp"
#include "Apoteka.hpp"




int Mikroorganizam::brojM=0;
void idiNegde( Mesto  & m, Covek & c)
{
    m.dodajCoveka(c);
    cout<<c.getIme()<<" "<<c.getPrezime()<<" ide u "<<m.getNaziv()<<endl;
    usleep(5000);
    int DaLiCeSeZaraziti= rand()%((int)floor(m.GustinaMesta())+1);//dodajem 1 da se ne bi moglo desiti deljenje sa 0
    if (m.GetBrojLjudi()<2 ||DaLiCeSeZaraziti!=0)//Sto je gustina mesta veca manje su sanse da se zarazi
    {

        cout<<c.getIme()<<" "<<c.getPrezime()<<" nije zarazen";
        if (c.getPol()==zenski){cout<<"a";}
        cout<<endl;
        return;
    }

    int cimeBiSeZarazio=rand()%(m.GetBrojLjudi()-1);//jer je novi covek koji je  dodat poslednji pa njega ne racunam
    Covek c2;
    cout<<cimeBiSeZarazio<<endl;
    c2=m.getLjudi()[cimeBiSeZarazio];
    if (c2.getStanje()==zdrav_covek)
    {
        cout<<c.getIme()<<" "<<c.getPrezime()<<" nije zarazen";
               if (c.getPol()==zenski){cout<<"a";}
               cout<<endl;
               return;

    }
    int x=rand()%c2.GetBrojBolesti();
    Bolest b2= (c2.GetBolesti())[x];
    c.Zarazi(b2,(c2.GetZO()[x]) );



}


  
Covek NapraviCoveka()
{
    string ime, prezime,pol;
    polCoveka PraviPol;
    int godine;
    
    cout<<"Unesite ime coveka koga biste zeleli da simulirate:"<<endl;
    cin>>ime;
    pisiTxt("Ljudi.txt", "100|",'a');
    pisiTxt("Ljudi.txt", ime+"|",'a');
    cout<<" Unesite prezime:"<<endl;
    cin>>prezime;
    pisiTxt("Ljudi.txt", prezime+"|",'a');
    pisiTxt("Ljudi.txt", "zdrav_covek|",'a');
    cout<<"Unesite pol (opcije : musko, zensko, drugo):"<<endl;
    cin>>pol;
    cout<<"Unesite godine:"<<endl;
    cin>>godine;
    pisiTxt("Ljudi.txt", to_string(godine)+"|",'a');
    if (pol=="musko"||pol=="Musko"||pol=="MUSKO"||pol=="muski"||pol=="Muski"||pol=="MUSKI")
    {
        PraviPol=muski;
    }
    if (pol=="zensko"||pol=="Zensko"||pol=="ZENSKO"||pol=="zenski"||pol=="Zenski"||pol=="ZENSKI")
    {
        PraviPol=zenski;
    }
    else
    {
        PraviPol=drugo;
    }
    pisiTxt("Ljudi.txt", pol+"|",'a');
    pisiTxt("Ljudi.txt","20000|",'a');
    Covek c(100,ime,prezime,zdrav_covek,godine,PraviPol,20000);
    clearscr();
    cout<<"Napravljen je novi Covek"<<endl;
    cout<<"Za pocetak mu je dodeljeno 20 000"<<endl;
    cout<<"Ovaj covek je zdrav sa 100/100 imunitetom"<<endl;
    cout<<c;
    return c;
    
}
void IspisiLjude()
{
    vector<string>ljudi=splitFile("Ljudi.txt");
    unsigned long int k=ljudi.size()/7;//brojljudi
    vector<string>imena,prezimena;
    for (int i=1; i<ljudi.size(); i +=7 )
    {
        imena.push_back(ljudi[i]);
    }
    for (int i=2; i<ljudi.size(); i +=7 )
    {
        prezimena.push_back(ljudi[i]);
    }
    for(int i=0; i< k; i ++)
    {
        cout<<i<<". "<<imena[i]<<" "<<prezimena[i]<<endl;
        
    }
    cout<<endl;
   
}
void meni()
{
    cout<<"////////////////////Dobar dan//////////////////////"<<endl;
    cout<<"Izaberite jednu od sledecih opcija: "<<endl;
    cout<<"1. Izaberi jednog od vec postojecih ljudi"<<endl;
    cout<<"2. Napravite novog coveka za simulaciju"<<endl;
    cout<<"3. Izadjite iz programa"<<endl;
}
StanjeCoveka to_StanjeCoveka(string s)
{
    if (s=="zdrav_covek")
    {
        return zdrav_covek;
    }
    if (s=="bolestan")
    {
        return bolestan;
    }
    else
    {
        return mrtav;
    }
}
polCoveka to_PolCoveka(string s)
{
    if (s=="zenski")
    {
        return zenski;
    }
    if (s=="muski")
    {
        return muski;
    }
    else
    {
        return drugo;
    }
}
void meni2()
{
    usleep(5000);
    cout<<"/////////////////Dobro dosli u Mikroorganis////////////////"<<endl;
    usleep(5000);
    cout<<"Kako biste otisli u nas cuveni restoran sa hranom ciji ukus morate osetiti pritisnite taster 1"<<endl;
    cout<<"Ukoliko biste ipak otisli u setnju kroz park obraslim zelenilom pritisnite taster 2"<<endl;
    cout<<"Mozete i otici u apoteku ako se ne osecate dobro i pritisnite taster 3"<<endl;
    cout<<"Da bi izasli iz programa pritisnite 4"<<endl<<endl;

    
}

Covek izaberiCoveka()
{
    cout<<"Izaberite nekoga"<<endl;
    IspisiLjude();
    string unos;
    cin>>unos;
    Covek c;
    vector<string>ljudi=splitFile("Ljudi.txt");
    unsigned long int k=ljudi.size()/7;//brojljudi
    vector<Covek> lj;
    vector<string>imena,prezimena;
    for (int i=0; i<ljudi.size(); i +=7 )
    {
       
       
        Covek x(stoi(ljudi[i]),ljudi[i+1],ljudi[i+2],to_StanjeCoveka(ljudi[i+3]),stoi(ljudi[i+4]),to_PolCoveka(ljudi[i+5]),stoi(ljudi[i+6]));
        lj.push_back(x);
    }
 
    for (int i=1; i<ljudi.size(); i +=7 )
    {
        imena.push_back(ljudi[i]);
    }
    for (int i=2; i<ljudi.size(); i +=7 )
    {
        prezimena.push_back(ljudi[i]);
    }
    for(int i=0; i<k; i ++)
    {
        if(unos==imena[i]||unos==prezimena[i])
        {
            cout<<"Odabrali ste "<<imena[i]<<" "<<prezimena[i]<<endl;
            return lj[i];
        }
        
    }
    cout<<"Ovaj covek ne postoji"<<endl;
    return Covek();
    
}
Covek CovekIzFajla(int n)
{
   vector<string>ljudi=splitFile("Ljudi.txt");
   int k=n*7;
    return Covek(stoi(ljudi[k]),ljudi[k+1],ljudi[k+2],to_StanjeCoveka(ljudi[k+3]),stoi(ljudi[k+4]),to_PolCoveka(ljudi[k+5]),stoi(ljudi[6]));
    
}

int main(int argc, const char * argv[]) {

   srand((unsigned int)time(NULL));
   vector<string> v=splitFile("Ljudi.txt");
    Covek c;
    string x;

    do{
    meni();
     cin>>x;
    if (x==to_string(1))
    {
        c=izaberiCoveka();
        break;
    }
    else if (x==to_string(2))
    {
        c=NapraviCoveka();
        break;
    }
    if (x==to_string(3))
    {
        return 1;
    }
        cout<<"Izaberite ponovo..."<<endl;
    clearscr();

    }while(x!= to_string(1)||x!=to_string(2)||x!=to_string(3));
    
    Parazit p1("Plasmodium",sporozoa);
    Bakterija b2("Clostridium Tetani",bacil), b3("Enterobakteriaceae",bacil);
    Organ o1("Crvena Krvna zrnca", zarazen), o2("Nervni sistem", zarazen), o3("Zeludacno-crevni trakt",zarazen);
    Hrana h1("pica",1,false,200),h2("salata", 3, false, 300), h3 ("sladoled",1, false, 100);
    Bolest blst1("Malarija",80,parazitska,&p1);
    Bolest blst2("Tetanus",85,bakterijska,&b2);
    Bolest blst3("Salmonela",15,bakterijska,&b3);
    Restoran r("Restooran",20.6);
    Apoteka a("AApoteka", 10.2);
    Lek lek1(pilula,"2901", 5, blst3, 1000),lek2(vakcina," protiv Tetanus", 20, blst2, 2000);
    Mesto p("Park",52.43);
    
    a.DodajLek(lek1);
    a.DodajLek(lek2);
    r.dodajHranu(h1);
    r.dodajHranu(h2);
    r.dodajHranu(h3);
    Covek c1(CovekIzFajla(0));
    Covek c2(CovekIzFajla(1));
    Covek c3(CovekIzFajla(2));

   if (c.getIme()==c1.getIme()&&c.getPrezime()==c1.getPrezime())
   {
       c2.Zarazi(blst3, o3);
       c2.Zarazi(blst1, o1);
       c3.Zarazi(blst2, o2);
       idiNegde(r, c2);
       idiNegde(p, c3);
       
   }
   if (c.getIme()==c2.getIme()&&c.getPrezime()==c2.getPrezime())
   {
       c3.Zarazi(blst3, o3);
       c3.Zarazi(blst1, o1);
       c1.Zarazi(blst2, o2);
       idiNegde(r, c1);
       idiNegde(p, c3);
       
   }
   if (c.getIme()==c3.getIme()&&c.getPrezime()==c3.getPrezime())
   {
       c1.Zarazi(blst3, o3);
       c1.Zarazi(blst1, o1);
       c2.Zarazi(blst2, o2);
       idiNegde(r, c1);
       idiNegde(p, c2);
   }
   else
    {
        c1.Zarazi(blst1, o1);
        c2.Zarazi(blst2, o2);
        c3.Zarazi(blst3, o3);
        idiNegde(r, c1);
        idiNegde(p, c2);
        idiNegde(r, c3);
        citajTxt("Ljudi.txt");
    }

    x="nesto";
    do
    {
      clearscr();
      citajTxt("Mapa.txt");
      meni2();
      cin>>x;
        if (x==to_string(1))
        {
            idiNegde(r, c);
            sleep(2000);
            clearscr();
            string y;
            do
            {
                cout<<"Ukoliko zelite da pojedate nesto i pogledate jelovnik pritisnite taster 1"<<endl;
                cout<<"Ukoliko zelite da izadjete iz restorana pritisnite taster 0"<<endl;
                cin>>y;
                if(y==to_string(1))
                {
                    c.pojedi(r.Naruci());
                    break;
                }
                if(y==to_string(0))
                {
                    r.izadji(c);
                    break;
                }
                cout<<"Ne mozemo da utvrdimo sta zelite na osnovu vaseg unosa"<<endl;
                cout<<"Pokusajte ponovo..."<<endl;
            }while(y!=to_string(1)||y!=to_string(0));
        }
        if (x==to_string(2))
        {
            idiNegde(p, c);
            sleep(2000);
            clearscr();
            citajTxt("Drvo.txt");
            string z;
            do
            {
               cout<<"Ako zelite da izadjete iz parka pritisnite 1"<<endl;
               cin>>z;
            }while(z!=to_string(1));
            
        }
        if (x==to_string(3))
        {
            idiNegde(a, c);
            sleep(2000);
            clearscr();
            string p;
            do
            {
                cout<<"Ukoliko zelite da kupite lek pritisnite taster 1"<<endl;
                cout<<"Ukoliko zelite da izadjete iz apoteke pritisnite taster 0"<<endl;
                cin>>p;
                if(p==to_string(1))
                {
                    c.Izleci(a.KupiLek());
                    break;
                }
                if(p==to_string(0))
                {
                    a.izadji(c);
                    break;
                }
                cout<<"Ne mozemo da utvrdimo sta zelite na osnovu vaseg unosa"<<endl;
                cout<<"Pokusajte ponovo..."<<endl;
            }while(p!=to_string(0)||p!=to_string(1));
            
        }
        
    }while(x!=to_string(4));
    

   //c1.pojedi(r1.Naruci());
    
  //METODE SU URADJENE U KLASI COVEK
  // Program sluzi za pracenje infekcija, lecenje, ozdravljenja, smrtnost i uticaja zivih organizama (mikroorganizama, zivotinja i drugih ljudi) na zdravstveno stanje ljudske populacije.
  //  Program  ce sadrzati file (bazu podataka) kao neku vrstu enciklopedije  koji ce cuvati podatke o tome koju bolest leci koji "lek". Kojoj se moze pristupiti tokom pokretanja programa, file koji cuva sva "desavanja" u programu dakle sva stanja ljudi i njihove interakcije.
  // U programu se prave ljudi koji se na osnovu razlicitih ponasanja mogu zaraziti ili izleciti. Na primer postoji klasa mesto, gde velika gustina(broj ljudi i zivotinja podeljen sa povrsinom) i ako je neko medju njima vec zarazen, moze uzrokovati zarazom svih ostalih koji se nalaze na ovoj poziciji.

    return 0;
}
