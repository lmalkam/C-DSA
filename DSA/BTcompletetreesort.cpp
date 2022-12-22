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

void cbt(BSTPTR &T,int a[],int i,int &j)
{
    T=new(trnode);
    if(i<8)
    T->data=0;
    else
    T->data=a[j++];
    T->leftchild=NULL;
    T->rightchild=NULL;
    if(2*i<16)
    cbt(T->leftchild,a,2*i,j);
    if(2*i+1<17)
    cbt(T->rightchild,a,2*i+1,j);
}

int replace(BSTPTR T,int k,int z){
    if(T==NULL)
    return 0;
    else
    {
        replace(T->leftchild,k,z);
        replace(T->rightchild,k,z);
        if(k==T->data)
        {
            T->data=z;
        }
    }
}

int printmin(BSTPTR T){

   // cout<<"checll"<<" ";
   // cout<<min;
    if(T==NULL)
    return INT8_MIN;

    if(T->data==0)
    {
        printmin(T->leftchild);
        return printmin(T->rightchild);
       // return INT8_MIN;
    }
    
    int data=T->data;
    int ldata=printmin(T->leftchild);
    int rdata=printmin(T->rightchild);

    if(ldata<data && ldata>0)
    data=ldata;
    if(rdata<data && rdata>0)
    data=ldata;

    return data;
}

void min(BSTPTR T,int &minn)
{
	if(T==NULL){
		return;
	}
	else{
		if(T->data < minn && T->data>0){
			minn=T->data;
		}
		min(T->leftchild,minn);
		min(T->rightchild,minn);
	}
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

   cbt(S,a,1,i);

   int j=999;

   for(int i=0;i<n;i++){
    min(S,j);
   cout<<j<<" ";
   replace(S,j,0);
   j=999;
   }


     return 0;
}