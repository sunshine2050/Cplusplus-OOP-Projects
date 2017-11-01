#include <iostream>
#include "Cirbuf.h"

using std::cout; using std::cerr; using std::endl;

Cirbuf::Cirbuf(int s)
{
    head = tail = length = 0;
    sz = s;
    cb = new char[s];
}

Cirbuf::~Cirbuf(){
    delete[] cb;
}

int Cirbuf::produce(char c){
    if(isFull()){
        cerr<<"Produce: buffer full"<<endl;
        return -1;
    }
    cb[tail] = c;
    length++;
    incr(tail);
    return 0;
}

int Cirbuf::consume(){
    char c;
    if(isEmpty()){
        cerr<<"consume: buffer empty"<<endl;
        return -1;
    }
    c = cb[head];
    length--;
    incr(head);
    return c;
}

