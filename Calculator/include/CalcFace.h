#ifndef CALCFACE_H
#define CALCFACE_H
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class CalcFace
{
    public:
        explicit CalcFace(char* k="+-*/=NnAaCc"){
            keys = string(k);
        }
        int input(char& c,double& number);
        void showNumber(double number) const;
        enum { OK = 0, OPONLY=1, OFF=2, PREC=6};


    protected:

    private:
        void buildNumber(char c, int& i);
        void extractNumber(double&) const;
        int inchar() const { return cin.get(); }
        string keys;
        char nbuf[PREC+2];
        int numb(char c);
};

#endif // CALCFACE_H
