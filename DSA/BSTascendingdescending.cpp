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

void maxmin(BSTPTR T,int min,int max)
{
    if(T==NULL)
    return;
    maxmin(T->leftchild,min,T->data-1); 
    maxmin(T->rightchild,T->data+1,max);
    cout<<T->data<<" "<<min<<" "<<max<<endl;
}

void printleft(BSTPTR T){

    if(T==NULL)
    return;
    printleft(T->leftchild);
    cout<<T->data<<" ";
    printleft(T->rightchild);
}

void printright(BSTPTR T){

    if(T==NULL)
    return;
    printright(T->rightchild);
    cout<<T->data<<" ";
    printright(T->leftchild);
}

int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    printleft(S->leftchild);
    cout<<"/ "<<endl;
    cout<<S->data<<"/ "<<endl;
    printright(S->rightchild);
    cout<<"/ "<<endl;

     return 0;
}