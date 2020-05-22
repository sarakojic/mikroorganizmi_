//
//  funkcije.h
//  mikroorganizmi
//
//  Created by Sara on 5/15/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef funkcije_h
#define funkcije_h
#include<iostream>


void clearscr (  )
{
  for ( int i = 0; i < 100; i++ )
    printf("\n");
}
void ispis ()
{
    
    cout<<"Dobar dan";
    
}
vector<string> splitSen(string str, char c='|')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}
vector<string> splitFile(string nazivFajla)
{
    vector<string> v,line ;
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            line=(splitSen(linija));
            v.insert(v.end(), line.begin(), line.end());
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";
    return v;
    
}

void pisiTxt(string nazivFajla, string tekst, char mode='a')
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
    fajl << tekst;

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
string FileString(string nazivFajla)
{
    string s;
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            s.append(linija+'\n');
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";
    return s;

    
}

void UpisiLjudeUFajl(vector<string> v)
{
    for(int i =0; i<v.size(); i+=7)
    {
        if(i==0)
        {
           pisiTxt("Ljudi.txt",v[i]+"|",'w');
        }
        else
            pisiTxt("Ljudi.txt",v[i]+"|");
        pisiTxt("Ljudi.txt",v[i+1]+"|");
        pisiTxt("Ljudi.txt",v[i+2]+"|");
        pisiTxt("Ljudi.txt",v[i+3]+"|");
        pisiTxt("Ljudi.txt",v[i+4]+"|");
        pisiTxt("Ljudi.txt",v[i+5]+"|");
        pisiTxt("Ljudi.txt",v[i+6]+"\n");
    }
    
}



#endif /* funkcije_h */
