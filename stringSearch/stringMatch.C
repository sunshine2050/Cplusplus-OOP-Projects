#include <string>

using namespace std;

int stringMatch(string& str,string& line){
    if(str.empty()) return -1;
    int j,k;
    int s1=str.size(), l1=line.size();
    for(int i=0;i<l1;i++){
        if(line[i]!=str[0]) continue;
        for(j=i+1, k=1;str[k]==line[j] && k<s1;j++,k++){}
        if(k==s1) return i;
        else
            if(j==l1) return -1;
    }
    return -1;
}
