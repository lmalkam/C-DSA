#include<iostream>
#include<cmath>
using namespace std;

struct stack
{
    int f,r,s;
    int que[100];
};

void enqueue(stack &q,int a){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else
        q.r=(q.r+1)%q.s;
        q.que[q.r]=a;
    }
}

int dequeue(stack &q){
    if(q.f==-1)
    cout<<"EMPTY";
    else{
        int t=q.que[q.f];
        if(q.r==q.f)
        {
            q.f=-1;
            q.r=-1;
        }
        else
        q.f=(q.f+1)%q.s;
        return t;
    }
}

int main(){

    stack q;q.f=-1;q.r=-1;q.s=50;

    int n;
    cin>>n;
    int i=0;
    int store=n;

    while(n>0){
        i++;
        enqueue(q,n%10);
        n=n/10;
    }

    int output=0;
    while(q.f!=-1){
        output=output*10+dequeue(q);
    }

    cout<<output;

    return 0;
}