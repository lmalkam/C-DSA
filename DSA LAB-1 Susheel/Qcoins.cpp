#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==-1)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
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

void path(BSTPTR T,int a[],int A[],int i,int key,int &n){

    if(T->data==key)
    { 
        a[i++]=T->data;
        for(int z=0;z<i;z++)
        A[z]=a[z];
        n=i;
        return;
    }
    a[i++]=T->data;
    if(T->leftchild!=NULL)
    path(T->leftchild,a,A,i,key,n);
    if(T->rightchild!=NULL)
    path(T->rightchild,a,A,i,key,n);
}

void maxnode(BSTPTR T,int &x)
{
    if(T!=NULL)
    {
        if(x<T->data)
        x=T->data;
        maxnode(T->leftchild,x);
        maxnode(T->rightchild,x);
    }
}

bool makeone(BSTPTR &T)
{
    if(T!=NULL)
    {
        if(T->data==0){
        T->data=1;
        }
        makeone(T->leftchild);
        makeone(T->rightchild);
    }
}

void checkone(BSTPTR T,int &count)
{
    if(T!=NULL)
    {
        if(T->data==0){
        count++;
        }
        makeone(T->leftchild);
        makeone(T->rightchild);
    }
}
int final=0;
int main(){
      
    BSTPTR S=NULL;
    make(S);

    int a[100];int A[100];int b[100];int B[100];int x=-999,y=0;int n1=0,n2=0;
    maxnode(S,x);int c1=0,c2=0;
   // cout<<x;
    while(x!=-1){
        int count=0;
        checkone(S,count);
        if(count==0)
        break; 
    path(S,a,A,0,x,n1);
    path(S,b,B,0,y,n2);
    n1--;  n2--;
    while(A[n1]!=B[n2])
    {
        if(n2>0){c2++;n2--;}
        if(A[n1]==B[n2])
        break;
        if(n1>0){c1++;n1--;}
    }
    final+=c1;
    final+=c2;
    c1=0;c2=0;
    makeone(S);
    }

    cout<<final;

     return 0;
}

