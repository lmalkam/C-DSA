#include<iostream>
using namespace std;

struct basic
{
    int top1,top2;
    int a[100];
    int b[100];
};

void push1(basic &s,int x)
{
    s.a[++s.top1]=x;
    return;
}

void push2(basic &s,int x)
{
    s.b[++s.top2]=x;
    return;
}

int pop1(basic &s)
{
    return s.a[s.top1--];
}

int pop2(basic &s)
{
    return s.b[s.top2--];
}

int main(){

    basic s;
    s.top1=-1;s.top2=-1;

    int arr[3];

    for(int i=0;i<3;i++)
    cin>>arr[i];
    
    int j=0;int i=1;
    push2(s,brr[j++]);
    push(s,i++)

    while(j<6)
    if(s.a[s.top1]==s.b[s.top2]){
        pop()
    }
    else{
        push1(s,i++)
    }

    



     return 0;
}