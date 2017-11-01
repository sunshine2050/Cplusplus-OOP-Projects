#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "CalcEng.h"
#include "CalcFace.h"
class Calculator
{
    public:
        Calculator(){};
        void on();

    protected:

    private:
        CalcEng eng;
        CalcFace cf;
};

#endif // CALCULATOR_H
