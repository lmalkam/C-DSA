#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild=NULL;
    int data,x,y;
    trnode *rightchild=NULL;
};

typedef trnode* BSTPTR;

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

void assignxy(BSTPTR T,int Xo,int Yo)
{
    if(T!=NULL)
    {
        T->x=Xo;
        T->y=Yo;
     //   cout<<Xo<<" "<<Yo<<" ";
        assignxy(T->leftchild,Xo-1,Yo+1);
        assignxy(T->rightchild,Xo+1,Yo+1);
    }
}

int getvalue(BSTPTR T,int y,int x)
{
    if(T!=NULL)
    {
        if(T->x==x && T->y==y)
        return T->data;
        getvalue(T->leftchild,y,x);
        getvalue(T->rightchild,y,x);
    }
}

void complete(BSTPTR &T,BSTPTR S)
{
    if(T!=NULL)
    {
        if(T->leftchild==NULL && T->rightchild!=NULL)
        {
            if(T->x>0 && T->y<=1)
            {
                T->leftchild=new(trnode);
                T->leftchild->data=(T->data+S->data)/2;
            }
            else if(T->y<=1)
            {
                T->leftchild=new(trnode);
                T->leftchild->data=(T->data)/2;
            }
            else
            {
                int x=getvalue(S,T->y-2,T->x);
                T->leftchild=new(trnode);
                T->leftchild->data=(T->data+x)/2;
            }
        }
        if(T->rightchild==NULL && T->leftchild!=NULL)
        {
            if(T->y<=2)
            {
                T->rightchild=new(trnode);
                T->rightchild->data=(T->data+S->data)/2;
            }
            else
            {
                int x=getvalue(S,T->y,T->x-2);
                cout<<T->y<<" "<<T->x<<" "<<x<<" ";
                T->rightchild=new(trnode);
                T->rightchild->data=(T->data+x)/2;
    
            }
        }
        complete(T->leftchild,S);
        complete(T->rightchild,S);
    }
}


int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }
    int i=0,j=0;
    assignxy(S,i,j);

    complete(S,S);cout<<endl;

   inorder(S);cout<<endl;
   preorder(S);

    
    return 0;
}