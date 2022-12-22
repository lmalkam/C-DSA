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

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==-1)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
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

bool check(int a[],int n)
{
    for(int i=2;i<n;i++)
    {
        if(a[i]!=a[i-1]+a[i-2])
        return 0;
    }
    return 1;
}
void path(BSTPTR T,int a[],int i){

    if(T->rightchild==NULL && T->leftchild==NULL)
    {   a[i++]=T->data;
        if(check(a,i))
        for(int z=0;z<i;z++)
        cout<<a[z]<<" ";
        cout<<endl;
        return;
    }

    a[i]=T->data;
    if(T->leftchild!=NULL)
    path(T->leftchild,a,i+1);
    if(T->rightchild!=NULL)
    path(T->rightchild,a,i+1);
}


int main(){
      
    BSTPTR S=NULL;
    make(S);

    int a[100];

    path(S,a,0);

    
    


     return 0;
}

