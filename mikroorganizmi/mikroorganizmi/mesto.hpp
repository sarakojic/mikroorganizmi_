//
//  mesto.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/22/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef mesto_h
#define mesto_h
#include "zivotinja.hpp"
#include "covek.hpp"
class Mesto{
protected:
    string naziv;
    double povrsina;
    vector<Covek> ljudi;

public:
    Mesto(){naziv=" "; povrsina=0;ljudi.push_back(Covek());}
    Mesto(string n,double p, vector<Covek> c){
        naziv= n;
        povrsina=p;
        for(auto i=c.begin();i!=c.end();i++)
        ljudi.push_back(*i);
    }
    Mesto(string n, double p){naziv=n; povrsina=p;}
    
    Mesto(const Mesto &m){naziv=m.naziv; povrsina=m.povrsina; ljudi=m.ljudi;}
    double GustinaMesta()
    {
        return (ljudi.size()/povrsina);
    }
    virtual void dodajCoveka(const Covek & c){ljudi.push_back(c);}
    string getNaziv(){return naziv;}
    virtual int TipMesta(){return 0;}
    int GetBrojLjudi(){return (int)ljudi.size();}
    vector<Covek> getLjudi(){return ljudi;}

    
};


#endif /* mesto_h */
