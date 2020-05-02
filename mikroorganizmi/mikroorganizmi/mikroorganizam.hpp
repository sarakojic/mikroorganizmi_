//
//  mikroorganizam.hpp
//  mikroorganizmi
//
//  Created by Sara on 4/25/20.
//  Copyright © 2020 Sara. All rights reserved.
//

#ifndef mikroorganizam_h
#define mikroorganizam_h
using namespace std;
class Mikroorganizam
{
protected:
    string naziv;

    
public:
    Mikroorganizam(string n): naziv(n){}
    Mikroorganizam(): naziv(" "){}
    Mikroorganizam(const Mikroorganizam & m){naziv=m.naziv;}
    
};

#endif /* mikroorganizam_h */
