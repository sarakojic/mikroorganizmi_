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
    usleep(4500000);
    int DaLiCeSeZaraziti= rand()%3;
    if (m.GetBrojLjudi()<2 ||DaLiCeSeZaraziti==0)
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


  void pisiTxt(string nazivFajla, string tekst, char mode='w')
  {
      /// fajl je sada objekat klase ofstream
      ofstream fajl;
  
      /// koristimo metodu open za otvaranja fajla
      /// kao parametar prosledjujemo naziv fajla i njegovu ekstenziju
      if (mode=='a'){
          fajl.open (nazivFajla, ios_base::app);
      }else{
          fajl.open (nazivFajla);
      }
  
      /// pisanje vrsimo tako sto umesto cout pisemo naziv fajla
      /// koristimo operator <<
      fajl << tekst << endl;
  
      /// na kraju zatvaramo fajl
      fajl.close();
  
  }

   
   void citajTxt(string nazivFajla)
   {
       string linija;
       ifstream fajl (nazivFajla);
       if (fajl.is_open())
       {
           while ( getline (fajl,linija) )
           {
               cout << linija << '\n';
           }
           fajl.close();
       }
   
       else
           cout << "Neuspesno otvoren fajl";
   
   }

  
int main(int argc, const char * argv[]) {
    
    
   //METODE SU URADJENE U KLASI COVEK
  // Program sluzi za pracenje infekcija, lecenje, ozdravljenja, smrtnost i uticaja zivih organizama (mikroorganizama, zivotinja i drugih ljudi) na zdravstveno stanje ljudske populacije.
  //  Program  ce sadrzati file (bazu podataka) kao neku vrstu enciklopedije  koji ce cuvati podatke o tome koju bolest leci koji "lek". Kojoj se moze pristupiti tokom pokretanja programa, file koji cuva sva "desavanja" u programu dakle sva stanja ljudi i njihove interakcije.
  // U programu se prave ljudi koji se na osnovu razlicitih ponasanja mogu zaraziti ili izleciti. Na primer postoji klasa mesto, gde velika gustina(broj ljudi i zivotinja podeljen sa povrsinom) i ako je neko medju njima vec zarazen, moze uzrokovati zarazom svih ostalih koji se nalaze na ovoj poziciji.
    srand((unsigned int)time(NULL));
    ZarazenOrgan zo1,zo2,zo3;
    Parazit p1("Plasmodium",sporozoa),p2;
    Bakterija b1, b2("Clostridium Tetani",bacil), b3("Enterobakteriaceae",bacil);

    Virus v1, v2, v3;

    Organ o1("Crvena Krvna zrnca", zarazen), o2("Nervni sistem", zarazen), o3("Zeludacno-crevni trakt",zarazen);
    Bolest blst1("Malarija",80, parazitska, &p1), blst2("Tetanus", 85,bakterijska,&b2 ), blst3("Salmonela", 15, bakterijska,&b3);
  
    Covek c1(100, "A","B",zdrav_covek,30,zenski,20000), c2(100, "C","D",zdrav_covek,35,muski,20000),c3(100, "E","F",zdrav_covek,20,drugo,20000);
   c2.Zarazi(blst3, o3);
    c2.Zarazi(blst1, o1);
    c3.Zarazi(blst2, o2);
  

    Hrana h1("pica",1,false,200),h2("salata", 3, false, 300), h3 ("sladoled",1, false, 100);
    
    Restoran r1("Restooran",20.6);
    Apoteka a1("AApoteka", 10.2);
    Lek lek1(pilula,"2901", 5, blst3, 1000),lek2(vakcina," protiv Tetanus", 20, blst2, 2000);
    a1.DodajLek(lek1);
    a1.DodajLek(lek2);
    idiNegde(a1, c2);
    c2.Izleci(a1.KupiLek());

    r1.dodajHranu(h1);
    r1.dodajHranu(h2);
    r1.dodajHranu(h3);
    idiNegde(r1, c2);
    idiNegde(r1, c3);
    idiNegde(r1, c1);
    
    
    c1.pojedi(r1.Naruci());
    cout<<c1.getStanje()<<endl;

    

    
  


    
    return 0;
}
