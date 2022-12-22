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
        q.r=(q.r+1)%q.s;}
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
    int a[100];
    int i=0;int m;
    while(i>=0){
          cin>>a[i];
          if(a[i]==-1)
              break;
          i++;
    }m=i;

    int half=m/2;

    stack s;stack q;
    s.top=-1;q.r=-1;q.f=-1;q.s=m;

    for(int i=0;i<m/2;i++)
    enqueue(q,a[i]);
    for(int i=m-1;i>=m/2;i--)
    push(s,a[i]);
    

    for(int i=0;i<half;i++){
        cout<<dequeue(q)<<" "<<pop(s)<<" ";
    }

     return 0;
}