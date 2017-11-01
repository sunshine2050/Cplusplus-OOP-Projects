#include <math.h>
#include "CalcEng.h"

CalcEng::CalcEng()
{
    allclear();
}

void CalcEng::allclear(){
    ans=arg=0.0;
    argcnt=1;
    op='=';
}

void CalcEng::operand(double in){
    if(op=='=') ans =in;
    else{
        arg = in;
        argcnt = 2;
    }
}

void CalcEng::operation(char nc){
    switch(nc)
    {
        case 'A':
        case 'a':
            allclear(); return;
        case 'N':
        case 'n':   if(argcnt == 1) ans = -ans;
                    else arg = -arg;
                    return;
        case 'C':
        case 'c':   if(argcnt == 1) ans = 0.0, op = '=';
                    else { arg = 0.0; argcnt = 1;}
                    return;
        default:    compute();
                    op = nc;

    }
}

void CalcEng::compute(){
    if(argcnt == 2){
        switch(op){
            case '+': ans+=arg; break;
            case '-': ans-=arg; break;
            case '*': ans*=arg; break;
            case '/': ans/=arg; break;
        }
        argcnt = 1;
    }
}
