#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
using std::string;

class Tokenizer
{
    public:
        Tokenizer(const string& str,const string& delim = WHITE,bool want_delim = false)
        :position(0),delimiter(delim),target(str),delimToken(want_delim){}
        bool moreToken() const;
        string nextToken();
        int tokenCount() const;
        string setDelimiter(const string& delim){ delimiter = delim;}

    private:
        string next();
        string nextAll();
        static const string WHITE;
        int position;
        const string& target;
        string delimiter;
        bool delimToken;

};

#endif // TOKENIZER_H
