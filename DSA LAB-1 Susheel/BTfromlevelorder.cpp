#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
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



void inorder(BSTPTR T){
    if(T!=NULL)
    {
        inorder(T->leftchild);
        cout<<T->data<<" ";
        inorder(T->rightchild);
    }
}

void preorder(BSTPTR T){
    if(T!=NULL)
    {
        cout<<T->data;
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
}



void construct(BSTPTR &T,stack &q)
{

    BSTPTR temp=dequeue(q);

  //  cout<<temp->data;

    char c;cin>>c;

    if(c=='$')
    return;

    if(c!='#')
    {
        BSTPTR L=new(trnode);
        L->data=c;
        L->leftchild=L->rightchild=NULL;
        temp->leftchild=L;
        enqueue(q,L);
    }
    else
    {
        temp->leftchild=NULL;
    }
    
    cin>>c;

    if(c=='$')
    return;

    if(c!='#')
    {
        BSTPTR R=new(trnode);
        R->data=c;
        R->leftchild=R->rightchild=NULL;
        temp->rightchild=R;
        enqueue(q,R);
    }
    else
    {
        temp->rightchild=NULL;
    }
    
    construct(T,q);
    
}

int main(){

    BSTPTR T=NULL;
    stack q;
    q.f=q.r=-1;
    q.s=100;

    char c;cin>>c;

    T=new(trnode);
    T->data=c;
    T->rightchild=T->leftchild=NULL;

    enqueue(q,T);

    construct(T,q);

   // preorder(T);
 //  inorder(T);

    while(q.r!=-1)
    {
        cout<<dequeue(q)->data<<" ";
    }
     

     return 0;
}