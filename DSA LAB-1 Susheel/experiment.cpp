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


void preorder(BSTPTR T){
    if(T==NULL){
        cout<<"0 ";
        return;
    }
    else
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

    
    preorder(S);cout<<endl;
    

     return 0;
}