#include "Calculator.h"

void Calculator::on()
{
    int ind;
    char op;
    double number;
    cf.showNumber(eng.output());
    while((ind=cf.input(op,number)) != CalcFace::OFF){
        if(ind == CalcFace::OK) eng.operand(number);
        eng.operation(op);
        number = (op=='c' || op=='C')?0:eng.output();
        cf.showNumber(number);
    }

}
