#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

struct pairs
{
    BSTPTR x,y;
};

struct stack
{
    int top;
    pairs sta[100];
};

void push(stack &s,pairs x){
    s.sta[++s.top]=x;
    return;
}

pairs pop(stack &s){
    return s.sta[s.top--];
}

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==0)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}

void preorder(BSTPTR T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
}

BSTPTR combine(BSTPTR &T1,BSTPTR &T2)
{
    stack s;
    s.top=-1;
    pairs t,p;
    t.x=T1;
    t.y=T2;
    push(s,t);
    while(s.top!=-1)
    {
        p=pop(s);

        if(p.x==NULL && p.y==NULL){
        continue;
        }

        if(p.x==NULL && p.y!=NULL)
        {
            p.x=new(trnode);
            p.x->rightchild=p.y->leftchild=NULL;
            p.x->data=p.y->data;
        }
        else if( p.x!=NULL and p.y!=NULL)
        p.x->data=p.x->data+p.y->data;
        else if(p.x!=NULL and p.y==NULL)
        p.x=p.x;

        if(p.x->leftchild==NULL){
        if(p.y->leftchild!=NULL)
        p.x->leftchild=p.y->leftchild;
        }
        else
        {
            pairs temp;
            temp.x=p.x->leftchild;
            temp.y=p.y->leftchild;
            push(s,temp);
        }

        if(p.x->rightchild==NULL)
        if(p.y->rightchild!=NULL)
        p.x->rightchild=p.y->rightchild;
        else
        {
            pairs temp;
            temp.x=p.x->rightchild;
            temp.y=p.y->rightchild;
            push(s,temp);
        }
    }
    return T1;
}

int main(){
      
    BSTPTR S1=NULL,S2=NULL,S3=NULL;

    make(S1);
    make(S2);

    S3=combine(S1,S2);

    preorder(S3);

     return 0;
}

/*

3 2 4 0 0 1 0 0 7 0 6 0 0
9 6 3 0 0 0 7 1 0 0 10 0 0

2 34 31 0 0 33 0 0 90 35 0 0 37 6 0 0 8 0 0 
1 2 4 0 0 5 8 0 0 0 3 6 0 9 0 0 7 0 0
*/
