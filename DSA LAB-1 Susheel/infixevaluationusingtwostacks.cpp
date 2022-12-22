#include<iostream>
#include<cstring>
using namespace std;

struct infix
{
    int top1;
    string final;
    char exist[100];
};

void push(infix &s,char x){
    s.exist[++s.top1]=x;
    return;
}
char pop(infix &s){
    return s.exist[s.top1--];
}
int pop2(infix &s){
    return s.exist[s.top1--];
}

void priority(infix &s,char x){
    if((x=='+' || x=='-') &&  s.exist[s.top1]=='*' || s.exist[s.top1]=='/'){
       while(s.top1!=-1)
           s.final+=pop(s);
    }
    if(x=='*' || x=='/' || x=='+' || x=='-')
        push(s,x);
}

int eval(char opr,int opd1,int opd2){
    if(opr=='*') return opd1*opd2;
    if(opr=='/')return opd1/opd2;
    if(opr=='-')return opd1-opd2;
    if(opr=='+')return opd1+opd2;
}

int main(){ 

    infix s;s.top1=-1;
    string str;cin>>str;
    s.final="";
        for(int i=0;i<str.length();i++){
            if(str[i]-'0'>=1 and str[i]-'0'<=9)
            s.final+=str[i];
            else
            priority(s,str[i]);
        }
        while(s.top1!=-1)
           s.final+=pop(s);
        int pass,x,y,value;
        for(int i=0;i<s.final.length();i++){
            pass=s.final[i]-'0';
            if(pass>=1 and pass<=9){
            push(s,pass);
            }
            else{
               x=pop2(s);
               y=pop2(s);
               value=eval(s.final[i],y,x);
               push(s,value);
            }
        }
        cout<<pop2(s);
     return 0;
}