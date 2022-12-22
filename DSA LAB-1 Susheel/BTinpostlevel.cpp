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

int replace(BSTPTR T,int k,int z){
    if(T==NULL)
    return 0;
    else
    {
        if(k<T->data)
        replace(T->leftchild,k,z);
        else if(k>T->data)
        replace(T->rightchild,k,z);
        else if(k==T->data)
        {
            T->data=z;
        }
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


int search(char rdl[],char ch)
{   
    int i=0;
    while(rdl[i]!=ch)
    i++;
  //  cout<<i;

    return i;
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

void construct(BSTPTR &T,char lrd[],char ldr[],int start,int end)
{ static int i=end;
    
    if(start>end)
    return;
    
    T=new(trnode);
    T->data=lrd[i];
   // cout<<T->data<<" ";
    T->leftchild=T->rightchild=NULL;
    if(i==0)
    return;
    int ind=search(ldr,lrd[i--]);
    construct(T->rightchild,lrd,ldr,ind+1,end);
    construct(T->leftchild,lrd,ldr,start,ind-1);
}

void levelorder(BSTPTR T,stack q,BSTPTR X)
{
    enqueue(q,T);
    enqueue(q,X);
    while(q.front!=-1){
    BSTPTR temp=dequeue(q);
    if(temp==NULL){
    if(q.front==-1)
    return;
    else{
    cout<<"/ ";
    enqueue(q,X);
    continue;
    }
    }
    else
    cout<<temp->data<<" ";
    if(temp->leftchild!=NULL)
    enqueue(q,temp->leftchild);
    if(temp->rightchild!=NULL)
    enqueue(q,temp->rightchild);
    }
}

int main(){

    char ldr[100];
    int i=0;

    cin>>ldr[i];
    while(ldr[i]!='#')
    {
        i++;
        cin>>ldr[i];
    }
    int m=i;i=0;

     char lrd[100];
    
    cin>>lrd[i];
    while(lrd[i]!='#')
    {
        i++;
        cin>>lrd[i];
    }
    int n=i;n--;

    BSTPTR S=NULL,X=NULL;

    construct(S,lrd,ldr,0,m-1);

    stack Q;
    Q.front=-1;
    Q.rear=-1;
    Q.size=100;
    
    levelorder(S,Q,X);

     return 0;
}
/*
DQLHMBEANIFCPSRTVWXZYUJKG#
QLMHDEBNIFSWZYXVUTRPKJGCA#
*/