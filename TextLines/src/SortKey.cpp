#include "SortKey.h"
#include <string>
#include <iostream>

using std::string;

const string SortKey::key(const string& s) const{
    int i =position;
    if(i == 0) return s;
    int i0=0, i1=0;
    while(i--){
        i0 = s.find_first_not_of(delim, i1);
        if(i0 == string::npos) return string();

        if(i1 == string::npos) return string();
    }
}
SortKey::~SortKey()
{
    //dtor
}
