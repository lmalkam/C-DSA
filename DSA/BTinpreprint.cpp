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

void construct(BSTPTR &T,char dlr[],char ldr[],int start,int end,int i)
{
    
    if(start>end)
    return;
    if(i==0)
    return;
    T=new(trnode);
    T->data=dlr[i];
    cout<<T->data<<" ";
    T->leftchild=T->rightchild=NULL;
    int ind=search(ldr,dlr[i--]);
    construct(T->rightchild,dlr,ldr,start,ind-1,i);
    construct(T->leftchild,dlr,ldr,ind+1,end,i);
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
    int n=i;

    BSTPTR S=NULL;

    construct(S,lrd,ldr,0,m-1,n-1);


    inorder(S);

     return 0;
}