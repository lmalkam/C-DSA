#include<iostream>
using namespace std;

struct stack
{
    int top=-1;
    int sta[100];
};


struct node
{
    node* leftchild;
    int data;
    node *rightchild;
};

typedef node* BSTPTR;

void push(stack &s,int x){
    s.sta[++s.top]=x;
    return;
}

int pop(stack &s){
    return s.sta[s.top--];
}

void insert(BSTPTR &T,int &k){

    if(T==NULL)
    {
        T=new(node);
        T->data=k;
        T->leftchild=NULL;
        T->rightchild=NULL;
    }
    else{
        if(k>T->data)
        {
            insert(T->rightchild,k);
        }
        else if(k<T->data){
            insert(T->leftchild,k);
        }
    }
}


void RDL(BSTPTR T,stack &s)
{
    if(T!=NULL)
    {
        RDL(T->rightchild,s);
        push(s,T->data);
        RDL(T->leftchild,s);
    }
}



void DR(BSTPTR T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
      
        DR(T->rightchild);
    }
}



int main()
{

    stack s;

    BSTPTR T1=NULL;

    int n;
    cin>>n;
    while(n!=-1)
    {
        insert(T1,n);
        cin>>n;
    }

    RDL(T1,s);

    BSTPTR T2=NULL;

    
    while(s.top!=-1)
    {
        n=pop(s);
        insert(T2,n);
    }

    DR(T2);

    return 0;
}