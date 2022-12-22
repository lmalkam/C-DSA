#include<iostream>
using namespace std;

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

    int a[100];

    int i=0;int m;
    while(i>=0){
          cin>>a[i];
          if(a[i]==0)
              break;
          i++;
    }m=i;

    int b;
    cin>>b;

    int c[m-b+1];

    int z=m-b+1;

    stack q;q.s=b;q.f=-1;q.r=-1;

    for(i=0;i<b;i++)
    enqueue(q,a[i]);
    i++;

    int count=b;
    int j=0;
    while(z!=0){
        int max=0;
        while(count!=0){
            int t=dequeue(q);
            t>max?max=t:max=max;
            enqueue(q,t);
            count--;
        }
        c[j++]=max;
        dequeue(q);
        enqueue(q,a[i++]);
        count=b;
        z--;
    }
    
    for(int i=0;i<z;i++)
    cout<<c[i]<<" ";

 return 0;
}
