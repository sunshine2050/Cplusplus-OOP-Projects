#ifndef RATE_H
#define RATE_H
#include <iostream>
#include <string>

using std::cout;
using std::string;

class Rate
{
    public:
        Rate(const char* name= "",double r =0.0):cur(string(name)),amt(r) {}
        double getRate() { return amt;}
        void setRate(double r){ amt = r;}
        const string& id() { return cur;}
        void display(){
            cout<<amt <<"\t\t"<<cur;
        }
    private:
        const string cur;
        double amt;
};

#endif // RATE_H
