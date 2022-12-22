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

    int a[100],b[100];

    int i=0;int m;
    while(i>=0){
          cin>>a[i];
          if(a[i]==-1)
              break;
          i++;
    }m=i;


    i=0;int n;
    while(i>=0){
          cin>>b[i];
          if(b[i]==-1)
              break;
          i++;
    }n=++i;

    stack s;s.top=-1;stack q;
    q.s=n;q.r=-1;q.f=-1;
    
    for(int i=m-1;i>=0;i--){
        push(s,a[i]);
    }
    for(int i=0;i<n;i++){
        enqueue(q,b[i]);
    }

    int c[100];

    for(int i=0;i<m+n-1;i++){
        if(i<m)
        c[i]=pop(s);
        else
        c[i]=dequeue(q);
    }
    
    for(int i=0;i<m+n-1;i++){
        cout<<c[i]<<" ";
    }
     return 0;
}