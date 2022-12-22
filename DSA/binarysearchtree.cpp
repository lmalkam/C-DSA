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

int findmax(BSTPTR T){
    while(T->rightchild!=NULL)
    T=T->rightchild;
    return T->data;
}

int findmin(BSTPTR T){
    while(T->leftchild!=NULL)
    T=T->leftchild;
    return T->data;
}

int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    
    preorder(S);cout<<endl;
    inorder(S);cout<<endl;
    postorder(S);cout<<endl;
    cout<<findmin(S)<<endl;
    cout<<findmax(S)<<endl;
    cin>>n;
    cout<<find(S,n)<<endl;
    cin>>n;
    cout<<find(S,n)<<endl;


     return 0;
}