#include "TextLines.h"
#include <iostream>

using std::string; using std::cin; using std::cout; using std::cerr; using std::endl;
using std::getline; using std::ios;
bool TextLines::insert(const string& l, int i){
    if(0 <= i && i < (int)line.size()) line.insert(line.begin() + i, new string(l));
    else if( i == (int)line.size()) line.push_back(new string(l));
    else return false;
    return true;
}

void TextLines::input(istream& in)
{
    int l = readLines(in);
    if( l > 0 ) return;
    if(l==-1) cerr<<"TextLines: failed to read input file."<<endl;
    if(l==0) cerr<<"TextLines: Input file empty" <<endl;
    in.setstate(ios::badbit);
}


int TextLines::readLines(istream& in){
    int error = 0, count = 0;
    string* t1 = new string();
    while(getline(in,*t1,'\n')){
        if(in.fail()){ error = -1; break;}
        line.push_back(t1);
        count++;
        t1 = new string();
    }

    return (error? error:count);
}

void TextLines::display(ostream& out) const
{
    for(unsigned i=0;i<line.size();i++){
        out<<*line[i]<<endl;
    }
}

TextLines::~TextLines(){
    unsigned len = line.size();
    while(len--) delete line[len];
}
