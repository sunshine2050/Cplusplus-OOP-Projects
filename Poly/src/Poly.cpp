#include "Poly.h"

using std::cout; using std::endl;

inline bool MAX(int x, int y) { return x > y ? x : y; }
inline bool MIN(int x, int y) { return x < y ? x : y; }

Poly::Poly(const int *p, int n)
{
    n *= 2;
    pol = new int[n+1];
    for(int i=0;i<n;i++) pol[i]=*p++;
    pol[n] = -1;
}

int Poly::length() const
{
    int i;
    for(i=0; pol[i]>-1;i+=2);
    return i+1;
}

Poly Poly::operator+(const Poly& q) const
{
    int *c, *a, *b, *tmp;
    unsigned len, d;
    len = length() + q.length() - 1;
    tmp = c = new(int[len]);
    a = pol; b =q.pol;
    while(*a >= 0){
        while(*b > *a){
            *c++ = *b++; *c++ = *b++;
        }
        *c++ = *a;
        if(*b == *a){
            *c = *++a + *++b;
            if(*c++ == 0) c-=2;
            b++;
        }
        else *c++ = *++a;
        a++;
    }
    while(*b >= 0) *c++ = *b++;
    *c = -1;
    Poly ans(tmp,(c-tmp)/2);
    delete tmp;
    return ans;
}

void Poly::display()
{
    int *p = pol;
    switch(*p)
    {
        case -1: cout<<"0"<<endl; break;
        case  0: cout<<p[1]<<endl; break;
        default:
            cout<<'(';
            while(*p>=0){
                cout<< *p << " " << *(p+1);
                p += 2;
                if(*p != -1) cout <<", ";
            }
            cout<<')';
    }
}

Poly Poly::operator-(const Poly& q) const
{
    int *a, *b, *tmp, *c;

    a= pol; b = q.pol;
    while(*b>=0){ *++b = -*++b; b++;}
    while(*a>=0){a+=2;}
    Poly A(a,(a-tmp)/2);
    Poly B(b,(b-tmp)/2);
    return A+B;

}
