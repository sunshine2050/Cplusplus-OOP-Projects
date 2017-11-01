#ifndef CIRBUF_H_INCLUDED
#define CIRBUF_H_INCLUDED

class Cirbuf
{
public:
    enum{ D_SIZE = 16};
    explicit Cirbuf(int sz = D_SIZE);
    int produce(char c); //insert char to buf
    int consume(); // remove last char from buf
    bool isEmpty(){ return(length == 0);}
    bool isFull(){ return(length == sz);}
    ~Cirbuf();
private:
    int head;  //first char in buf
    int tail;  //last char in buf
    int length;
    int sz;
    char *cb; //pointer to buf
    void incr(int& x){
        if(++x == sz) x=0;
    }
};

#endif // CIRBUF_H_INCLUDED
