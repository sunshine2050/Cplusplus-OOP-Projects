#ifndef SORTKEY_H
#define SORTKEY_H
#include <string>
using std::string;

class SortKey
{
    public:
        explicit SortKey(int pos = 0,const char* dlm="\n\t \r"){
            delim = dlm;
            position = pos;
        }
        void setDelim(const char* s){ delim = s; }
        int lineCompare(const string& a, const string& b) const;
        int keyCompare(const string& k, const string& l) const
        {return k.compare(key(l));}
        ~SortKey();

    private:
        int position;
        string delim;
        const string key(const string& s) const;
};

#endif // SORTKEY_H
