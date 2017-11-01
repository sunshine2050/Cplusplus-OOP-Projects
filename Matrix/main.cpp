#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    double a[2][3] = { {1.0,-2.0,5.0}, {1.0,2.0,3.0}};
    double b[3][2] = { {9.0,7.0}, {-2.0,3.0}, {-1.0,4.0}};
    Matrix x(*a, 2, 3);
    Matrix y(*b, 3, 2);
    Matrix z(2,2);
    x.times(y,z);
    z.display();
    return 0;
}
