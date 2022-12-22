#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
    int x;
    int y;
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


void insert(BSTPTR &T,int &k){

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
        else if(k<T->data){
            insert(T->leftchild,k);
        }
    }
}

void preorder(BSTPTR T){
    if(T==NULL){
        return;
    }
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    
}

void inorder(BSTPTR T){
    if(T==NULL)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        cout<<T->data<<" ";
        if(T->rightchild!=NULL)
        inorder(T->rightchild);
    
}

void make(BSTPTR &T)
{
	char c; cin>>c;
	if(c=='#')
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}



void leftview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->leftchild!=NULL)
    leftview(T->leftchild,cl+1,lpl);
    if(T->rightchild!=NULL)
    leftview(T->rightchild,cl+1,lpl);
}

void rightview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->rightchild!=NULL)
    rightview(T->rightchild,cl+1,lpl);
    if(T->leftchild!=NULL)
    rightview(T->leftchild,cl+1,lpl);
}

void assignxy(BSTPTR &T,int &innumb,int lev)
{
    if(T!=NULL){
    if(T->leftchild!=NULL);
    assignxy(T->leftchild,innumb,lev+1);
   // cout<<innumb<<lev;
    T->x=++innumb;
    T->y=lev;
    if(T->rightchild!=NULL)
    assignxy(T->rightchild,innumb,lev+1);
    }

}

void levelorder(BSTPTR T,stack q,BSTPTR X,int &o)
{   int c;
    enqueue(q,T);
    enqueue(q,X);
    while(q.front!=-1){
    static int prev=0;
    BSTPTR temp=dequeue(q);
    if(temp==NULL){
    if(q.front==-1){
        for(int i=o;i<9;i++)
    cout<<"*";
        cout<<"/";
    return;}
    else{
    for(int i=o;i<9;i++)
    cout<<"*";
    cout<<"/ ";
    cout<<endl;
    o=0;
    enqueue(q,X);
    continue;
    }
    }
    else{
    for(c=1;c<temp->x-o;c++)
    cout<<"*";
    cout<<temp->data;
    if(temp->leftchild!=NULL)
    enqueue(q,temp->leftchild);
    if(temp->rightchild!=NULL)
    enqueue(q,temp->rightchild);
    o=temp->x;
    }
    }
}

int main(){
      
    BSTPTR S=NULL;

    int n;cin>>n;
    while(n!=-1)
    {
        insert(S,n);
        cin>>n;
    }
    int i=0,j=0;
    assignxy(S,i,j);

    stack q;
    q.front=-1;
    q.rear=-1;
    q.size=100;

    BSTPTR X=NULL;
    i=0;

    levelorder(S,q,X,i);
     return 0;
}
/*
5 8 3 4 1 9 6 7 2 -1
*/
     