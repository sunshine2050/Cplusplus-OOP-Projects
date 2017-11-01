#include <iostream>
#include <Tokenizer.h>
using namespace std;

int main()
{
    string t("This is a test.");
    Tokenizer tk(t,"\r\t \n",true);
    while(tk.moreToken()){
        cout<<tk.tokenCount()<<"="<<tk.nextToken()<<endl;
    }
}
