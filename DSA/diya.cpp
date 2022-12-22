#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};

typedef trnode * LPTR;

LPTR find_end(LPTR L)
{
    while(L->next!=NULL)
        L=L->next;
    return L;
}
void add_end(LPTR &L,int x)
{
    if(L!=NULL)
    {
        LPTR E,T;
        T=new(trnode);
        T->data=x;
        T->next=NULL;
        E=find_end(L);
        E->next=T;
    }
    else
    {
        L=new(trnode);
        L->data=x;
        L->next=NULL;
    }
}
void print(LPTR L)
{
    if(L==NULL)
        return ;
    else
    {
        cout<<L->data<<" ";
        print(L->next);
    }
}

void add_front(LPTR &L,int x)
{
    LPTR T;
    T=new(trnode);
    T->data=x;
    T->next=L;
    L=T;
    print(L);
    cout<<endl;
}

void create(LPTR &L,int n)
{
    if(n>0)
    {
        int k=n%10;
        create(L,n/10);
        add_end(L,k);
    }
}

void reverse(LPTR &L,LPTR r1,LPTR r2)
{
    if(r2->next==NULL)
    {
        r2->next=r1;
        L=r2;
    }
    else
    {
        reverse(L,r1->next,r2->next);
        r2->next=r1;
        r1->next=NULL;
    }
}

void del(LPTR &L,int x)
{
    LPTR S=L,E=L->next;
    if(S->data==x)
        L=L->next;
    else
    {
        while(E!=NULL)
        {
            if(E->data==x)
               S->next=E->next;
            E=E->next;
            S=S->next;
        }
    }
}

void addition(LPTR L1, LPTR L2,int c=0)
{
    LPTR L3=NULL;
    int k1,k2;
    if(L1==NULL && L2==NULL && c!=0)
        add_end(L3,c);
    else if(L1!=NULL && L2!=NULL)
    {
        k1=find_end(L1)->data;
        k2=find_end(L2)->data;
        del(L1,k1);
        del(L2,k2);
        int sum=k1+k2+c;
        if(sum<10)
            add_end(L3,sum);
        else
            add_end(L3,sum%10);
        addition(L1,L2,sum/10);
    }
    print(L3);
}
int main()
{
    LPTR L1=NULL, L2=NULL;
    int x,y;
    cin>>x>>y;
    create(L1,x);
    create(L2,y);
    addition(L1,L2);
}