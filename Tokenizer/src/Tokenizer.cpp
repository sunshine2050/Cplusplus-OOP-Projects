#include "Tokenizer.h"

const string Tokenizer::WHITE = string("\r \n\t");

bool Tokenizer::moreToken() const
{
    if(position == target.length()) return false;
    if(delimToken) return true;
    int i0=target.find_first_not_of(delimiter,position);
    return i0 != string::npos;
}

string Tokenizer::nextToken(){
    if(delimToken) return nextAll();
    else return next();
}

int Tokenizer::tokenCount() const{
    if(position >= target.length()) return 0;
    int count = 0;
    int i0 = position, i1 = position;
    while(1){

        i0 = target.find_first_not_of(delimiter,i1);
        if(i0 == string::npos) return (!delimToken ? count : count + target.length() - i1);
        count++;
        if(delimToken) count+=i0-i1;
        i1 = target.find_first_of(delimiter,i0);
        if(i1 == string::npos) return count;
    }
}

string Tokenizer::next(){
    int i0 = position, i1=position;
    if(i0>=target.length()) return string();
    i0 = target.find_first_not_of(delimiter,i1);
    if(i0==string::npos) return string();
    i1 = target.find_first_of(delimiter,i0);
    if(i1==string::npos) i1=target.length();
    position = i1;
    return string(target,i0,i1-i0);
}

string Tokenizer::nextAll(){
    int i0 = position, i1 = position;
    if(i0>=target.length()) return string();
    i0 = target.find_first_not_of(delimiter,position);
    i1 = target.find_first_of(delimiter,position);
    if(i0 == string::npos) i0 = target.length();
    if(i1 == string::npos) i1 = target.length();
    if(i0<=i1) return next();
    position = i0;
    return string(target,i1,i0-i1);
}


