#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;

class Fraction {
    private:
        int nom;
        unsigned int denom;
        Fraction makeFraction(int n, unsigned d)
        {
            Fraction ans;
            ans.nom = n; ans.denom = d;
            return ans;
        }

    public:
        Fraction(){}
        Fraction(int n, unsigned d);
        Fraction operator- ();
        Fraction operator- (Fraction& y);
        Fraction operator+ (Fraction& y);
        Fraction operator* (Fraction& y);
        Fraction operator/ (Fraction& y);
        void display();
        bool operator==(Fraction& y);
        bool operator>(Fraction& y);
        bool isZero() {return (denom == 1 && nom == 0);}
        bool isOne() {return (denom == 1 && nom == 1);}
        bool isInt() { return denom == 1;}
        int floorF();
        int ceiling();
        Fraction power(Fraction a,int n);
        friend ostream& operator <<(ostream& out,const Fraction& cf)
        {
            out<<cf.nom <<"/"<<cf.denom;
            return out;
        }

};


#endif // FRACTION_H
