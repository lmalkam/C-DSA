#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};

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

typedef trnode* LPTR;


LPTR findend(LPTR L){
    while(L->next!=NULL)
    L=L->next;
    return L;
}

void addend(LPTR L,int n){
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=NULL;
    E=findend(L);
    E->next=T;
}


void combine(LPTR L1,LPTR L2,int k,stack &s)
{

    if(k==0)
    return;


    if(L1->data==L1->next->data)
    return combine(L1->next,L2,k,s);


    if(L2->data==L2->next->data)
    return combine(L1,L2->next,k,s);

    if(L1->data<L2->data)
    {
        push(s,L1->data);
        return combine(L1->next,L2,k-1,s);
    }

    if(L2->data<L1->data)
    {
        push(s,L2->data);
        return combine(L1,L2->next,k-1,s);
    }

    if(L1->data==L2->data){
        push(s,L1->data);
    return combine(L1->next,L2->next,k-1,s);}


}
int main(){

    LPTR L1;
    int n;cin>>n;
    L1=new(trnode);
    L1->data=n;
    L1->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L1,n);
    cin>>n;
    }

    LPTR L2;
    cin>>n;
    L2=new(trnode);
    L2->data=n;
    L2->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L2,n);
    cin>>n;
    }

    int k;
    cin>>k;

    stack s;
    s.top=-1;

    combine(L1,L2,k,s);

    while(s.top!=-1)
    cout<<pop(s)<<" ";
    return 0;
}