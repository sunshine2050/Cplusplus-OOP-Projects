#include "Fraction.h"
#include <stdlib.h>
#include <cmath>
#include <fstream>

int gcd(int a,int b){ return (b?gcd(b,a%b):a);}
Fraction::Fraction(int n, unsigned d)
{
    if(!n){nom = 0; denom = 1; return;}

    if(!d){ cerr<<"denominator is zero"<<endl; exit(1);}
    if(d<0){ n = -n; d = -d; }
    int g;
    if((g=gcd(n,d))!=1){
        nom=n/g;
        denom=d/g;
    }
    else {
        nom = n; denom = d;
    }
}
inline void Fraction::display(){ cout<<nom<<"/"<<denom;}
inline Fraction Fraction::operator-(){ return makeFraction(-nom,denom);}
inline bool Fraction::operator==(Fraction& y){return (nom == y.nom && denom == y.denom);}

Fraction Fraction::operator-(Fraction& y){
    if(!nom){ return makeFraction(-y.nom,y.denom);}
    else if(!y.nom){return *this;}
    else {return Fraction((nom * y.denom - denom * y.nom) , (y.denom * denom));}

}
Fraction Fraction::operator+(Fraction& y){
    if(!nom){ return makeFraction(y.nom,y.denom);}
    else if(!y.nom){return *this;}
    else {return Fraction((nom * y.denom + denom * y.nom) , (y.denom * denom));}

}
Fraction Fraction::operator*(Fraction& y){
    if(!nom || !y.nom){ return makeFraction(0,1);}
    else {return Fraction((nom * y.nom) , (y.denom * denom));}

}
Fraction Fraction::operator/(Fraction& y){
    if(!y.nom){cerr<<"Can't divide by zero"<<endl; exit(1);}
    else {return Fraction((nom * y.denom) , (denom * y.nom));}

}

int Fraction::floorF(){
    return floor(nom/(denom*1.0));
}
int Fraction::ceiling(){
    return ceil(nom/(denom*1.0));
}

Fraction power(Fraction a, int n){
    Fraction ans(1,1);
    for(int i=0;i<n;i++){
        ans = ans * a;
    }
    return ans;
}
int main(){
    Fraction x(1,30), u(-1,60), v(-1,60), t(0,5), f(1,2);
    Fraction y;
    x.display();
    cout<<endl;
    y = power(x,2);
    y.display();
    cout<<endl;
    cout<<x<<endl;
    return 0;
}
