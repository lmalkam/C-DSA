#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

struct stack
{
    int f,r,s;
    BSTPTR que[100];
};

void enqueue(stack &q,BSTPTR x){
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

BSTPTR dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
    else{
        BSTPTR t=q.que[q.f];
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



void printer(BSTPTR T1,BSTPTR T2,stack q1,stack q2)
{
    enqueue(q1,T1);
    enqueue(q2,T2);
    while(q1.r!=-1)
    {
        BSTPTR X=dequeue(q1);
        BSTPTR Y=dequeue(q2);
        if(X==NULL && Y!=NULL)
        cout<<Y->data<<" ";
        else if(Y==NULL && X!=NULL)
        cout<<X->data<<" ";
        else
        cout<<X->data+Y->data<<" ";
        if(T1->leftchild!=NULL)
        enqueue(q1,X->leftchild);
        else
        enqueue(q1,NULL);
        if(T2->leftchild!=NULL)
        enqueue(q2,Y->leftchild);
        else
        enqueue(q2,NULL);
        if(T2->rightchild!=NULL)
        enqueue(q2,Y->rightchild);
        else
        enqueue(q2,NULL);
    }

}

int main(){
      
    BSTPTR S1=NULL,S2=NULL;

    make(S1);
    make(S2);

    stack q1,q2;
    q1.f=q2.f=q1.r=q2.r=-1;
    q1.s=q2.s=100;

    printer(S1,S2,q1,q2);

     return 0;
}