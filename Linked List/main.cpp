#include <iostream>
#include <List.h>
using namespace std;

int main()
{
    List a('B');
    a.putOn('A');
    a.append('D'); a.append('E');
    cout<<endl;
    a.append('F'); a.display();
    cout<<endl;

    ListCell* lp = a.find('B');
    a.display(lp); cout<<endl;
    a.insert('C',lp); a.display();
    cout<<endl;
    a.remove('F'); a.shorten(2);
    a.display();
    cout<<endl;
}
