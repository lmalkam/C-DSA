#include<iostream>
using namespace std;

struct pushpop2
{
    int top1;
    int top2;
    int ush[6];
    int op[6];
};

void push(pushpop2 &s,int x){
    s.ush[++s.top1]=x;
    return;
}

void push2(pushpop2 &s,int x){
    s.op[++s.top2]=x;
    return;
}

int pop(pushpop2 &s){
    return s.ush[s.top1--];
}

int pop2(pushpop2 &s){
    return s.op[s.top2--];
}

int main(){

    pushpop2 s;s.top1=-1;s.top2=-1;

    int a[6],b[6];
    for(int i=0;i<6;i++)
    cin>>a[i];
    for(int i=0;i<6;i++)
    cin>>b[i];

    int i=-1,j=-1;
    push2(s,b[++j]);

    while(j<6){
        if(s.ush[s.top1]==s.op[s.top2]){
            cout<<"X";
            pop(s);
            pop2(s);
            push2(s,b[++j]);
        }
        else{
            push(s,a[++i]);
            cout<<"S";
        }
    }

     return 0;
}