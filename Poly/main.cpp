#include <iostream>
#include "Poly.h"

using namespace std;

int main()
{
    int p[] = {3,1,2,-1,0,1,-1};
    int r[] = {3,1,2,1,0,1,-1};
    Poly s(p,3);
    s.display();
}
