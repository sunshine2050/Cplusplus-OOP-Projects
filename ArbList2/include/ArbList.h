#ifndef ARBLIST_H
#define ARBLIST_H
#include <iostream>
typedef void* Any;

class ArbCell
{
    friend class ArbList;
    private:
        Any item;
        ArbCell* next;
        ArbCell(Any c = NULL, ArbCell* ptr = NULL)
        : item(c), next(ptr) {}
};

class ArbList{
    public:
        typedef bool (* EQ_FN)(Any,Any);
        typedef void (* DISP_FN)(Any);
        ArbList(Any c, EQ_FN eq, DISP_FN d);
        static ArbCell* next(ArbCell* p){ return p->next; }
        static Any content(ArbCell* p){ return p->item; }
        static bool isEnd(ArbCell* p){ return p ==NULL; }
        ArbCell* first() const { return head; }
        ArbCell* last();
        ArbCell* find(Any c);
        bool substitute(Any r, Any c);
        int remove(Any c);
        int shorten(int n);
        bool putOn(Any c);
        bool insert(Any c, ArbCell* cell);
        bool append(Any c){ return insert(c,last());}
        void display(ArbCell* p) const;
        void display() const{ display(head);}
        bool isEmpty() const { return head == NULL;}
        ~ArbList();
    private:
        EQ_FN equalfn;
        DISP_FN dispfn;
        void free();
        ArbCell* head;
};
#endif // ARBLIST_H
