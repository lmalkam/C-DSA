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
        else if(k<T->data){
            insert(T->leftchild,k);
        }
    }
}

void preorder(BSTPTR T){
    if(T==NULL){
        return;
    }
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    
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

void printer(BSTPTR T){
    if(T==NULL){
    return;}
    cout<<T->data<<" ";
    inorder(T);cout<<endl;
    printer(T->leftchild);
    printer(T->rightchild);
}

void cbt(BSTPTR &T,int i,int k)
{
    if(k>=0){
    T=new(trnode);
    T->data=i;
    T->leftchild=NULL;
    T->rightchild=NULL;
    if(2*i<16)
    cbt(T->leftchild,2*i,k);
    if(2*i+1<17)
    cbt(T->rightchild,2*i+1,k);
    }
    merge(T);
}

int main(){
      
    BSTPTR S=NULL;

   // make(S);
   int a[100];
   int i=0;int x;cin>>x;
   while(i>=0){
       if(x==-1)
       break;
       a[i++]=x;
       cin>>x;
   }

    int n=i;i=0;

   for(int z=0;z<n;z++)
   cout<<a[z]<<" ";

   cbt(S,1);

    preorder(S);
  //  inorder(S);

     return 0;
}