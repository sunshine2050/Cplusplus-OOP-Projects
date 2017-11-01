#include <iostream>
#include <string>
#include <ArbList.h>
using std::cout; using std::endl; using std::string;

void strDisp(string* str){
    cout<<*str;
}

bool strEq(string* a,string* b){
    return *a==*b;
}
int main()
{
    string a[]={"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty"};
    ArbList sList(a+1,reinterpret_cast<ArbList::EQ_FN>(strEq),reinterpret_cast<ArbList::DISP_FN>(strDisp));

    sList.putOn(a+3);
    sList.putOn(a+5);
    sList.display();cout<<endl;

    sList.putOn(a);
    sList.putOn(a+2);
    sList.append(a+4);
    sList.display();cout<<endl;

    sList.remove(a+4);
    sList.remove(a);
    sList.display(); cout<<endl;

    sList.shorten(3);
    sList.display(); cout<<endl;
    sList.shorten(1);
    sList.display(); cout<<endl;
}
