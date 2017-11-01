#include <iostream>
#include <strstream>
#include "CalcFace.h"

 using std::istrstream;

 int CalcFace::numb(char c){ return c=='.' || isdigit(c);}

 void CalcFace::showNumber(double number) const
 { cout<<"Calc:  " << number << endl; }

 void CalcFace::extractNumber(double& number) const
 {
    if(nbuf[0]=='\0') number=0.0;
    else{
        istrstream tmp(nbuf, PREC +1);
        tmp >> number;
    }

 }

 int CalcFace::input(char& op,double& number)
 {
    char c;
    int current_position = 0,num = 0;
    while((c=inchar())){
        if(keys.find(c) != string::npos){
            op = c;
            if(num){
                nbuf[current_position] = '\0';
                extractNumber(number);
                return OK;
            }
            else return OPONLY;
        }
        if(numb(c) && current_position<PREC){
            num = 1;
            buildNumber(c,current_position);
        }
    }
    return OFF;
 }

 void CalcFace::buildNumber(char c,int& i){
    static int point_seen = 0;
    if(!i) point_seen = 0;
    if(!i && c=='0') return;
    if(c=='.'){
        if(point_seen) return;
        else point_seen = 1;
    }
    nbuf[i++] = c;
 }
