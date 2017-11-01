#include "ArbList.h"

ArbList::ArbList(Any c,EQ_FN eq,DISP_FN d)
: head(new ArbCell(c,NULL)),equalfn(eq),dispfn(d){}

ArbList::~ArbList()
{
    free();
}


void ArbList::display(ArbCell* p) const
{
    std::cout<<"(";
    while(p){
        dispfn(p->item);
        if(p = p->next) std::cout<< " ";
    }
    std::cout<< ")";
}

int ArbList::remove(Any c){
    ArbCell *tmp, *p = head;
    int count = 0;
    if(p == NULL) return count;

    while(p->next){
        if(equalfn((p->next)->item, c)){
            count++;
            tmp = p->next;
            p->next = tmp->next;
            delete(tmp);
            return count;
        }
        else p= p->next;
    }

    if(equalfn(head->item,c)){
        tmp = head;
        head = head->next;
        delete(tmp);
        count++;
    }
    return count;

}

ArbCell* ArbList::find(Any c){
    for(ArbCell* p=head;p;p =p->next){
        if(equalfn((p->next)->item,c)) return p;

    }
    return NULL;
}


void ArbList::free(){
    ArbCell *tmp,*p = head;
    while(p){
        tmp = p;
        p= p->next;
        delete(tmp);
    }
}

int ArbList::shorten(int n){
    while(n-- && head){
        ArbCell* tmp =head;
        head = head->next;
        delete(tmp);
    }
    return - ++n;
}

ArbCell* ArbList::last(){
    ArbCell *p;
    for(p = head ;p && p->next;p=p->next );
    return p;
}

bool ArbList::substitute(Any r, Any c){
    ArbCell *tmp = find(r);
    if(tmp==NULL) return false;
    tmp->item = c;
    return true;
}

bool ArbList::putOn(Any c){
    ArbCell *tmp = new ArbCell(c,head);
    if(tmp == NULL) return false;
    head = tmp;
    return true;
}

bool ArbList::insert(Any c, ArbCell* cell){
    ArbCell *tmp = find(cell->item);
    if(tmp == NULL) return false;
    tmp = new ArbCell(c,cell->next);
    if(tmp==NULL) return false;
    cell->next = tmp;
    return true;
}
