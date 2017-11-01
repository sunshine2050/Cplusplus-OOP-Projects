#include <iostream>
#include "WordCount.h"

using std::cout; using std::endl;

int main()
{
    WordCount counter;
    for(;;)
    {
        if(counter.readin()) counter.count();
        else { counter.count(); break;}
    }
    cout << "total " << counter.getCount() << " words" <<endl;
}
