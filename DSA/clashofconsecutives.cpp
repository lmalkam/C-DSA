#include<iostream>
using namespace std;

struct infix
{
    int top1,top2,exist[100],sol[100];
};

void push(infix &s,int x){
    s.sol[++s.top2]=x;
    return;
}

int pop(infix &s){
    return s.exist[s.top1--];
}

int pop2(infix &s){
    return s.sol[s.top2--];
}

void clash(infix &s){

    if(s.top1==-1){
    while(s.top2>=0)
        cout<<pop2(s)<<" ";
    return;
    }

    if(s.sol[s.top2]==s.exist[s.top1]){
        pop(s);pop2(s);
        return clash(s);
    }

    push(s,s.exist[s.top1]);
    pop(s);
    return clash(s);
}


int main(){
      
    infix s;s.top2=-1;
    int i=-1;
    while(i>=-1){
        cin>>s.exist[++i];
        if(s.exist[i]==-1)
        break;
    }i--;s.top1=i;

    clash(s);
    return 0;
}