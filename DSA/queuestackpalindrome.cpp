#include<iostream>
using namespace std;

struct stack
{
    int top;
    int sta[100];
};

void push(stack &s,int x){
    s.sta[++s.top]=x;
    return;
}

int pop(stack &s){
    return s.sta[s.top--];
}

struct stack
{
    int f,r,s;
    int que[100];
};

void enqueue(stack &q,int x){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else{
        q.r=(q.r+1)%q.s;
        }
        q.que[q.r]=x;
    }
}

int dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
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

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    stack s;s.top=-1;stack s2;s2.top=-1;
    stack q;q.f=-1;q.r=-1;q.s=50;

    for(int i=0;i<n;i++)
        push(s,a[i]);
    
    for(int i=0;i<n/2;i++){
        int temp=pop(s);
        enqueue(q,temp);
    }
    if(n%2!=0)
    pop(s);
    for(int i=0;i<n/2;i++){
        int temp=pop(s);
        push(s2,temp);
    }  
    bool flag=true;
    while(s2.top!=-1){
         if(pop(s2)!=dequeue(q)){
         flag=false;break;
         }
    }
    cout<<flag;
    return 0;

}