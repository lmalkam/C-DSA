#include<iostream>
using namespace std;

struct bal
{
    string in;
    char elements[100];
    int top;
};

void push(bal &s,char x){
     s.elements[++s.top]=x;
     return;
}

int pop(bal &s){
    return s.elements[s.top--];
}

int main(){

    bal s;
    getline(cin,s.in);s.top=-1;
    for(int i=0;i<s.in.length();i++){
        if(s.in[i]=='{' || s.in[i]=='[' || s.in[i]=='(' )
        push(s,s.in[i]);
        if((s.elements[s.top]=='{' && s.in[i]=='}')  || (s.elements[s.top]=='[' && s.in[i]==']') || (s.elements[s.top]=='(' && s.in[i]==')'))
        pop(s);
    }
    s.top==-1?cout<<"1":cout<<"0";
     return 0;
}