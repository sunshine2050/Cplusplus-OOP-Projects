#include <iostream>
#include "RateTable.h"

using std::cout; using std::endl;

int main()
{
    RateTable::display();
    RateTable::newRate("Taiwan (NT $)", 34.5);
}
