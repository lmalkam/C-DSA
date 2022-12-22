#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

struct bsnode
{
    int data;
    bsnode *right;
    bsnode *left;
};

typedef bsnode* DLPTR;  

DLPTR findend(DLPTR D)
{
 while(D!=NULL)
 {
     if(D->right==NULL)
     {
         return D;
     }
     D=D->right;
 }
}

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
    if(T==NULL)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        cout<<T->data<<" ";
        if(T->rightchild!=NULL)
        inorder(T->rightchild);
    
}

void preorder(BSTPTR T){
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
}

DLPTR middle(DLPTR i,DLPTR j){
    if(j==NULL || j->right==NULL)
    return i;
    return middle(i->right,j->right->right);
}

void construct(BSTPTR &T,DLPTR start,DLPTR end)
{ 

    if(start==end->right)
    return;
    else{
    
    T=new(trnode);
    DLPTR mid=middle(start,start);
    T->data=mid->data;
    T->leftchild=T->rightchild=NULL;
    if(start!=mid){
    mid->left->right=NULL;
    construct(T->leftchild,start,mid->left);
    construct(T->rightchild,mid->right,end);
    }
    }
}
void addend(DLPTR &D,int x){
    if(D==NULL){
        D = new bsnode;
        D->left = NULL;
        D->data = x;
        D->right = NULL;
    }
    else{
        DLPTR E = findend(D);
        DLPTR T=new(bsnode);
       T->data=x;
       E->right=T;
       T->left=E;
       T->right=NULL;
    }
}

int main(){

    int n;DLPTR L=NULL;
	cin>>n;
	while (n!=-1)
	{
		addend(L, n);
		cin>>n;
	}

    BSTPTR S=NULL;

    DLPTR T=L;
    while(T->right!=NULL)
    T=T->right;

    construct(S,L,T);
    
    preorder(S);

     return 0;
}