#include <string.h>
#include "RateTable.h"

using std::endl; using std::cout;

Rate RateTable::table[]= {RATES};
unsigned RateTable::len = sizeof(RateTable::table)/sizeof(Rate);


int RateTable::lookup(char *cur){
    int low =0,high = len-1,mid,test;
    while(low<=high){
        mid = (low+high)/2;
        test = (table[mid].id()).compare(cur);
        if(test==0) return mid;
        else if(test<0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

double RateTable::rate(char *cur){
    int index = lookup(cur);

    if(index>-1) return table[index].getRate();
    else return 0.0;
}

int RateTable::newRate(char *cur, double r){
    int index = lookup(cur);
    if(index>-1){
        table[index].setRate(r);
        return 0;
    }
    else return -1;
}

void RateTable::display(char *cur){
    int index = lookup(cur);
    if(index > -1){
        table[index].display();
        cout<<endl;
    }
    else cout<<"Entry "<<cur<<" not found."<<endl;
}

void RateTable::display(){
    cout<<"len ="<<len <<endl;
    for(unsigned i=0;i<len;i++){
        table[i].display();
        cout<<endl;
    }
}
