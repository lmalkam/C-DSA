#include<iostream>
using namespace std;

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
        q.f=0;}
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
      
      stack s;s.top=-1;
      stack q;q.f=-1;q.r=-1;q.s=50;

      int a[6];

      for(int i=0;i<6;i++)
      cin>>a[i];

      for(int i=0;i<6;i++)
      enqueue(q,a[i]);

          for(int i=0;i<6;i++){
              int t=dequeue(q);
              if(t%2!=0)
              push(s,t);
              else
              enqueue(q,t);
          }

          while(s.top!=-1){
          int t=pop(s);
          enqueue(q,t);
          }

          for(int i=0;i<6;i++){
              int t=dequeue(q);
              if(t%2==0)
              push(s,t);
              else
              enqueue(q,t);
          }

          while(s.top!=-1){
          int t=pop(s);
          enqueue(q,t);
          }

          while(q.f!=-1){
              cout<<dequeue(q)<<" ";
          }

        
     return 0;
}