#include <iostream>
#include "List.h"
using std::cout;
class ListCell
{
    friend class List;

    private:
        char item;
        ListCell* next;
        ListCell(char a='\0',ListCell* ptr = NULL)
        : item(a), next(ptr) {}
};

List::List(char c): head(new ListCell(c,NULL)){}

List::~List()
{
    free();
}

void List::free(){
    ListCell *n, *p = head;
    while(p){
        n = p ->next;
        delete p;
        p = n;
    }
}

int List::shorten(int n){
    while(--n && head){
        ListCell* tmp=head;
        head = head->next;
        delete(tmp);
    }
    return - ++n;
}

int List::remove(char c){
    ListCell *tmp, *p=head;
    if(p==NULL) return 0;
    int count = 0;
    while(p->next){
        if((p->next)->item == c){
            count++;
            tmp = p->next;
            p->next = tmp->next;
            delete(tmp);
        }
        else p = p->next;
    }
    if(head->item = c){
        tmp = head;
        head = head->next;
        delete(tmp);
        count++;

    }
    return count;
}

bool List::putOn(char c){
    ListCell* tmp = new ListCell(c,head);
    if(tmp){
        head = tmp;
        return true;
    }
    return false;
}


bool List::insert(char c,ListCell* cell){
    if( cell==NULL) return putOn(c);
    ListCell *tmp = new ListCell(c,cell->next);
    if(tmp){
        cell->next = tmp;
        return true;
    }
    return false;
}

ListCell* List::last(){
    ListCell* tmp = head;
    while(tmp && tmp->next) tmp = tmp->next;
    return tmp;
}

ListCell* List::find(char c){
    for(ListCell *p =head; p ; p=p->next){
        if(p->item == c) return p;
    }
    return NULL;
}

bool List::substitute(char r,char c){
    ListCell *p = find(c);
    if(p==NULL) return false;
    p->item = r;
    return true;
}

void List::display(ListCell* p) const
{
    cout<<"(";
    while(p){
        cout<< p->item;
        if(p=p->next) cout<<" ";

    }
    cout<<")";
}


