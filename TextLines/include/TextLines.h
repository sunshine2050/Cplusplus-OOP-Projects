#ifndef TEXTLINES_H
#define TEXTLINES_H
#include <vector>
#include <iostream>
#include <string>

using std::string; using std::istream; using std::vector; using std::ostream;

class TextLines
{
    public:
        TextLines(int cap=512){ line.reserve(cap);}
        int length() { return line.size();}
        void swap(int i, int j);
        void input(istream& in);
        void remove(int i);
        ~TextLines();

        string* operator[](int i) const
        {
            return (i>=0 && i<(int)line.size())? line[i]: NULL;
        }
        void display(ostream& out) const;
        bool insert(const string& l, int i);

    private:
        int readLines(istream& in);
        vector <string*> line;
};

inline void TextLines::swap(int i, int j){
    string* tmp = line[i];
    line[i] = line[j];
    line[j] = tmp;
}

inline void TextLines::remove(int i)
{
    delete line[i];
    line.erase(line.begin()+i);
}

#endif // TEXTLINES_H
