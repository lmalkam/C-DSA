#include<iostream>
using namespace std;
struct trnode
{
    int data;
    trnode *next;
};
typedef trnode *LPTR;
LPTR findend(LPTR L)
{
    while(L->next!=NULL)
        L=L->next;
        return L;
}
void print(LPTR L)
{
    while(L!=NULL)
    {
        cout<<L->data<<" ";
        L=L->next;
    }
}
void addend(LPTR &l,int n)
{
  //  LPTR e;
    if(l==NULL)
    {
        l=new(trnode);
        l->data=n;
        l->next=NULL;
    }
    else
    {
        LPTR t,e;
        t=new(trnode);
        t->data=n;
        t->next=NULL;
        e=findend(l);
        e->next=t;
    }
    
}
void addfront(LPTR &l,int n1)
{
    LPTR m;
    m=new(trnode);
    m->data=n1;
    m->next=l;
    l=m;
}
void evenodd(LPTR p,LPTR &l1,LPTR &l2)
{
    while(p!=NULL)
    {
        if(p->data%2!=0)
        {
            addend(l2,p->data);
        }
        else
        {
            addend(l1,p->data);
        }
        p=p->next;
    }
}

int main()
{
    LPTR P,l1,l2;
    l1=NULL;l2=NULL;
    int num;
    cin>>num;
    P=new(trnode);
    P->data=num;
    P->next=NULL;
    cin>>num;
    while(num!=-1)
    {
        addend(P,num);
        cin>>num;
    }
    evenodd(P,l1,l2);
    print(l2);cout<<endl;
    print(l1);
}