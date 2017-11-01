#ifndef LIST_H
#define LIST_H


class ListCell;

class List
{
    public:
        List(): head(NULL){};
        List(char c);
        ListCell* first(){ return head;}
        ListCell* last();
        ListCell* find(char c);
        char content(ListCell* p);
        bool substitute(char r, char s);
        int remove(char c);
        void remove(ListCell* cell);
        int shorten(int n); //removes first n cells
        bool putOn(char c);
        bool insert(char c, ListCell* cell); //inserts c after cell
        int append(char c){ return insert(c,last()); }
        void display(ListCell* p) const;
        void display() const { display(head); }
        bool isEmpty() const {return head==NULL; }
        ~List();

    private:
        ListCell* head;
        void free();
};

#endif // LIST_H
