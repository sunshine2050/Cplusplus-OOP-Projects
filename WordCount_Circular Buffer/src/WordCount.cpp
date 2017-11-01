#include <iostream>
#include "WordCount.h"

using std::cin;

bool WordCount::readin()
{
    char c;
    while(!buf->isFull()){
        if(cin.get(c)){
            buf -> produce(c);
        }
        else return false;
    }
    return true;
}

void WordCount::count()
{
    int c;
    while(!buf->isEmpty()){
        switch(c = buf->consume())
        {
            case ' ':
            case '\t':
            case '\n':
                if(word) wcnt++;
                word = false;
                break;
            default:
                word = true;

        }
    }

}
