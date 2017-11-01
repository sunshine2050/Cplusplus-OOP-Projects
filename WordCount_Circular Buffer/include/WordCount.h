#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#include "Cirbuf.h"

class WordCount
{
    public:
        WordCount(){
            buf = new Cirbuf(128);
            wcnt = 0;
            word = false;
        }
        ~WordCount() { delete buf; }
        bool readin();
        void count();
        int getCount() { return wcnt;}

    private:
        int wcnt;
        bool word;
        Cirbuf* buf;
};
#endif // WORDCOUNT_H
