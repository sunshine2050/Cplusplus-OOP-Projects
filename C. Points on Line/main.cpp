#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n<3 || d < 2){
        cout<<0<<endl;
        return 0;
    }
    long long i =0;
    long long k =2;
    long long c =0;
    while(i<n){
        while(k<n && a[k]-a[i]<=d){
            c+= ((k-i-1)*(k-i))/2;
            k++;
            //cout<<":>>"<<i<<":>>"<<k<<endl;
        }
        i++;
    }
    cout<<c<<endl;
}
