#ifndef RATETABLE_H
#define RATETABLE_H
#include "Rate.h"

class RateTable
{
    public:
        RateTable(){}
        static double rate(char *cur);
        static int newRate(char *cur, double r);
        static void display(char *cur);
        static void display();

    private:
        static int lookup(char *cur);
        static Rate table[];
        static unsigned len;
};

#define RATES Rate("Britain (Pound)", 0.6967),\
        Rate("Canada (Dollar)", 1.4728),\
        Rate("Germany (Mark)", 2.0176),\
        Rate("European (Euro)", 1.0916),\
        Rate("Japan (Yen)", 106.10),\
        Rate("Mexico (New Peso)", 9.922),\
        Rate("Spain (Peseta)", 171.64),
#endif // RATETABLE_H
