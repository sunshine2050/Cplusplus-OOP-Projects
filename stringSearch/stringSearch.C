#include <iostream> // using cin/cout
#include <string>  // using type(string)
#include <fstream> // using input/output from folders

using namespace std;

void match(string& str,istream& in,ostream& out){
    if(str.empty()){
        cerr<<"empty match string"<<endl;
        exit(1);
    }
    string line;
    while(getline(in,line,'\n')){
        if(stringMatch(str,line) > 0) out<<line<<endl;
    }
    out.flush();
}
