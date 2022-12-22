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
    int front;
    int rear;
    int size;
    BSTPTR elements[100];
};

void enqueue(stack &Q,BSTPTR x){
    if(Q.rear+1%Q.size==Q.front)
    cout<<"FULL";
    else{
        if(Q.rear==-1)
        {
            Q.rear=0;Q.front=0;
        }
        else{
        Q.rear=(Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear]=x;
    }
}

BSTPTR dequeue(stack &Q){
    if(Q.front==-1)
    cout<<"";
    else{
        BSTPTR t=Q.elements[Q.front];
        if(Q.rear==Q.front)
        {
            Q.front=-1;
            Q.rear=-1;
        }
        else
        Q.front=(Q.front+1)%Q.size;
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

void levelorder(BSTPTR T,stack &Q){
    
    if(T==NULL){
        return;
    }
    else{
        while(Q.front!=-1){
            BSTPTR temp=dequeue(Q);
            cout<<temp->data<<" ";
            if(temp->leftchild!=NULL)
            enqueue(Q,temp->leftchild);
            if(temp->rightchild!=NULL)
            enqueue(Q,temp->rightchild);
    }
}
}


int main()
{
      
    BSTPTR P=NULL;
    int n;
    cin>>n;
    while(n!=-1){
        insert(P,n);
        cin>>n;
    }

    stack Q;
    Q.front=-1;
    Q.rear=-1;
    Q.size=100;
    enqueue(Q,P);
    levelorder(P,Q);

     return 0;
}