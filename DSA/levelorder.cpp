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
    cout<<"";
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

void insert(BSTPTR &T,int k){

    if(T==NULL)
    {
        T=new(trnode);
        T->data=k;
        T->leftchild=NULL;
        T->rightchild=NULL;
    }
    else{
        if(k>T->data)
        {
            insert(T->rightchild,k);
        }
        else{
            insert(T->leftchild,k);
        }
    }
}

int find(BSTPTR T,int k){
    if(T==NULL)
    return 0;
    else
    {
        if(k<T->data)
        find(T->leftchild,k);
        else if(k>T->data)
        find(T->rightchild,k);
        else if(k==T->data)
        return 1;
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
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
}

void postorder(BSTPTR T){
    if(T!=NULL)
    {
        postorder(T->leftchild);
        postorder(T->rightchild);
        cout<<T->data<<" ";
    }
}

void levelorder(BSTPTR T,stack &q){
    if(T==NULL){
    return;
    }
    else{
    BSTPTR X=NULL;
    cout<<T->data<<" ";
    if(q.f==-1)
    enqueue(q,X);
    if(T->leftchild!=NULL)
    enqueue(q,T->leftchild);
    if(T->rightchild!=NULL)
    enqueue(q,T->rightchild);
    if(q.f!=-1)
    levelorder(dequeue(q),q);
    
    }
}


int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    stack q;
    q.f=-1;
    q.r=-1;q.s=100;


    levelorder(S,q);

     return 0;
}