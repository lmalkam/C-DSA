#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
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

void search(BSTPTR &C,BSTPTR &P,int x)
{
    while(C->data!=x && C!=NULL)
    {
        P=C;
        if(x<C->data)
        C=C->leftchild;
        else
        C=C->rightchild;
    }
}

BSTPTR getmax(BSTPTR T)
{
    while(T->rightchild!=NULL)
    T=T->rightchild;

    return T;
}

void del(BSTPTR &T,int x)
{
         BSTPTR P=NULL,C=T;
         search(C,P,x);

     if(C->leftchild==NULL && C->rightchild==NULL){    
         if(P->rightchild==C){
         P->rightchild=NULL;
         }
         else{
         P->leftchild=NULL;
         }
         return;
    }
    
    BSTPTR M=getmax(C->leftchild);
    int value=M->data;
    del(T,M->data);
    C->data=value;
}

int main(){
      
    BSTPTR S=NULL;
    int n;
    cin>>n;
    while(n!=-1)
    {
        insert(S,n);
        cin>>n;
    }

    cin>>n;
    while(n!=-1)
    {
        del(S,n);
        cin>>n;
    }

    inorder(S);

     return 0;
}