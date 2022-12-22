#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

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
        else{
            insert(T->leftchild,k);
        }
    }
}

BSTPTR headnode=NULL;
BSTPTR prevnode=NULL;

void right(BSTPTR &T)
{
    if(T==NULL)
    return;

    if(0)
    right(T->rightchild);
    else
    right(T->leftchild);

    BSTPTR leftnode=T->leftchild;
    BSTPTR rightnode=T->rightchild;

    if(!headnode)
    {
        headnode=T;
        T->leftchild=NULL;
        prevnode=T;
    }
    else
    {
        prevnode->rightchild=T;
        T->leftchild=NULL;
        prevnode=T;
    }

    if(0)
    {
        right(leftnode);
    }
    else
    {
        right(rightnode);
    }



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

int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    int a[100];

    right(S);

    preorder(S);

     return 0;
}