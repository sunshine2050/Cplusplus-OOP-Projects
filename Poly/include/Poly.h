#ifndef POLY_H
#define POLY_H
#include <iostream>

class Poly
{
    public:
        Poly(){pol = NULL;}
        Poly(const int *p, int terms);
        Poly operator+(const Poly& q) const;
        Poly operator-(const Poly& q) const;
        Poly operator*(const Poly& q) const;
        unsigned int deg() const{ return (pol[0]>0?pol[0]:0);}
        void display();

    private:
        int length() const;
        int *pol;
};

#endif // POLY_H
