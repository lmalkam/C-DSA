#include<iostream>
using namespace std;

struct stack
{
    int top=-1;
    int sta[100];
};

void push(stack &s,int x){
    s.sta[++s.top]=x;
    return;
}

int pop(stack &s){
    return s.sta[s.top--];
}

void reverse(stack &s)
{
    if(s.top==-1)return;
    int x=pop(s);
    cout<<x<<" /";
    reverse(s);
    push(s,x);
    cout<<x<<"?";
}

int main()
{

    stack s;

    int n;
    cin>>n;
    while(n!=-1)
    {
        push(s,n);
        cin>>n;
    }

    reverse(s);

    while(s.top!=-1)
    cout<<pop(s)<<" ";


    return 0;
}