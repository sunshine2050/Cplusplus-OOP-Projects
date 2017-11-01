#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


int main(int argc,char* argv[])
{
    ifstream infile("");
    if(infile.fail()){
        cerr<<"Can't open "<<""<<endl;
        exit(1);
    }
    ofstream outfile("");
    cout << "Hello world!" << endl;
    return 0;
}
