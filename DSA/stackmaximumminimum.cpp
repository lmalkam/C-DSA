#include<iostream>
using namespace std;

struct pos{
    int min,max;
};

struct aux
{
    int top;int size;
    pos sta[100];
};

struct stack
{
    int top;int size;
    int sta[100];
};

void push(stack &s,int x)
{
	if(s.top==s.size-1) cout<<"stack is full...";
	s.top=s.top + 1;
	s.sta[s.top]=x;
}

void push2(aux &a,int max,int min){
    a.top=a.top+1;
    a.sta[a.top].max=max;
    a.sta[a.top].min=min;
}

int pop(stack &s)
{
	if(s.top==-1) cout<<"stack is empty...";	
	else return s.sta[s.top--];
}

pos pop2(aux &a){
    pos t=a.sta[a.top--];
    return t;
}

int main(){

    stack s;s.top=-1;stack s2;s2.top=-1;
    aux a;s.size=50;s2.size=50;
    a.top=-1;

    int arr[100];
    int i=0;
    while(i>=0){
        cin>>arr[i];
        if(arr[i]==-1)
        break;
        i++;
    }
    int n=i;

    for(int i=0;i<n;i++)
        push(s,arr[i]);
     
    for(int i=0;i<n;i++){
        int t=pop(s);
    push(s2,t);
    }
    int temp=pop(s2);
    int min=temp,max=temp;
    push(s,temp);
    pos p;
    p.min=temp;p.max=temp;
    push2(a,p.max,p.min);

    while(s2.top!=-1){
        int t=pop(s2);
        push2(a,p.max<t?p.max=t:p.max=p.max,p.min>t?p.min=t:p.min=p.min);
        push(s,t);
    }

    while(s.top!=-1)
    cout<<pop(s)<<" ";
    
    cout<<endl;
    while(a.top!=-1){
        pos temp=pop2(a);
        cout<<temp.max<<" "<<temp.min<<" ";
    }

     return 0;
}