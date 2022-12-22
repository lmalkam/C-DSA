#include<iostream>
#include<cstring>
using namespace std;

struct one
{
    int top;
    int elements[100];
    
};

struct two{
    int top;
    char elements[100];

};

void push(one &s,int x){
    s.elements[++s.top]=x;
    return;
}

void push(two &s,char x){
    s.elements[++s.top]=x;
    return;
}

int pop(one &s){
    return s.elements[s.top--];
}

int pop(two &s){
    s.top--;
}

int eval(char opr,int opd1,int opd2){

    if(opr=='*')
    return opd1*opd2;
    if(opr=='/')
    return opd1/opd2;
    if(opr=='-')
    return opd1-opd2;
    if(opr=='+')
    return opd1+opd2;
}


int main(){

         one a;a.top=-1;
        int input=1234;;
        while(input!=0){
            push(a,input%10);
            input/=10;
        }
        while(a.top>=0){
            cout<<pop(a)<<" ";
        }
        cout<<endl;
    

        two s;s.top=-1;
        string inp="{{{}{}}}{}";
        for(int i=0;i<10;i++){
            if(inp[i]=='{')
            push(s,inp[i]);
            else
            pop(s);
        }
        s.top==-1?cout<<"1":cout<<"0";
        cout<<endl;
    

    
        one c;c.top=-1;
        string in="345*+2-";int pass,x,y,value;
        for(int i=0;i<in.length();i++){
            pass=in[i]-'0';
            if(pass>=1 and pass<=9){
            push(c,pass);
            }
            else{
               x=pop(c);
               y=pop(c);
               value=eval(in[i],y,x);
               push(c,value);
            }
        }
        cout<<pop(c);
    

     return 0;
}