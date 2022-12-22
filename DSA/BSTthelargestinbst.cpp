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

void maxmin(BSTPTR T,int min,int max)
{
    if(T==NULL)
    return;
        if(T->data>min and T->data<max){
        maxmin(T->leftchild,min,T->data-1);
        maxmin(T->rightchild,T->data+1,max);
        if(T->leftchild!=NULL and T->rightchild!=NULL)
        cout<<T->data<<" "<<findmax(T->leftchild)+1<<" "<<findmin(T->rightchild)-1<<endl;
        else if(T->leftchild!=NULL and T->rightchild==NULL)
        cout<<T->data<<" "<<T->leftchild->data+1<<" "<<max<<endl;
        else
        cout<<T->data<<" "<<min<<" "<<max<<endl;
        }
}

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==0)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}


int main(){
      
    BSTPTR S=NULL;
  //  int n;cin>>n;
    make(S);

    int i=0;
    int j=99999;

    maxmin(S,i,j);

     return 0;
}