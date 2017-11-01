#include <iostream>

using namespace std;

int main()
{
    int n,q;
    cin>>n;
    long long a[n+1];
    long long s1[n+1];
    long long s2[n+1];
    a[0] = 0;
    s1[0] = 0;
    s2[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s1[i] = s1[i-1] + a[i];
    }
    for(int i=0;i<3;i++){
        int x,y;
        cin>>x>>y;
        cout<<s1[y]-s1[x-1]<<endl;
    }
}
