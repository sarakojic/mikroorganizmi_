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

using namespace std;

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

 

    Parazit p1("Plasmodium",sporozoa),p2;
    Bakterija b1, b2("Clostridium Tetani",bacil), b3("Enterobakteriaceae",bacil);
    Virus v1, v2, v3;
    Organ o1("Crvena Krvna zrnca", zarazen), o2("Nervni sistem", zarazen), o3("Zeludacno-crevni trakt",zarazen);
    Bolest blst1("Malarija",o1,80, parazitska, p1), blst2("Tetanus",o2, 85,bakterijska,b2 ), blst3("Salmonela", o3, 15, bakterijska,b3);

    Covek c1, c2, c3;
    Zivotinja z1, z2, z3;
    Lek l1, l2, l3;
    Mesto ms1, ms2, ms3;
    
  // string BolestiFajl = "bolest.txt";
  /* string ulaz;
    getline(cin,ulaz);

  pisiTxt(BolestiFajl, ulaz);*/
    
   citajTxt("bolest.txt");

    

    
    return 0;
}
