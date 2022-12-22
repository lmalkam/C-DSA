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
void left(BSTPTR T){

    if(T==NULL)
    {
        return;
    }
    if(T->leftchild!=NULL){
    cout<<T->leftchild->data<<" ";
    left(T->leftchild);
    }
     if(T->rightchild!=NULL)
    left(T->rightchild);
}

void right(BSTPTR T){

    if(T==NULL)
    {
        return;
    }

    if(T->leftchild!=NULL){
    
    right(T->leftchild);
    }
     if(T->rightchild!=NULL){
         cout<<T->rightchild->data<<" ";
    right(T->rightchild);}
}

void fillin(BSTPTR T,int a[],int &i,int n)
{
    if(T!=NULL){
    if(i<n)
    {
        fillin(T->leftchild,a,i,n);
        T->data=a[i++];
        fillin(T->rightchild,a,i,n);
    }
    }
}

void paths(BTP)

int main(){
      
    BSTPTR S=NULL;
    make(S);
    int a[100]={1,2,3,4,5,6,7,8};
    int i=0;
    fillin(S,a,i,8);
    inorder(S);

     return 0;
}