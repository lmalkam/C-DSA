#include<iostream>
#include<cmath>
using namespace std;


struct stack
{
    int f=-1,r=-1,s=100;
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

void print(int a[])
{
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
}

void radix(int a[],stack s[],int n,int limit)
{
    static int x=1;
    if(limit==0)
    return;
    int b=0;

    for(int j=0;j<n;j++)
    {
        int dig=(a[j]/x)%10;
        enqueue(s[dig],a[j]);
    }

    for(int j=0;j<10;j++){
			while(s[j].r!=-1){
				a[b]=dequeue(s[j]);b++;
			}
		}

    x=x*10;
    return radix(a,s,n,limit-1);
}


int main(){

    int n=10;

    int a[10];
    for(int i=0;i<10;i++)
    cin>>a[i];

    stack s[10];

    radix(a,s,n,10);

    print(a);


     return 0;
}