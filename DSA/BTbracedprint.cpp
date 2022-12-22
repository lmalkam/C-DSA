#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
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
    else
    {
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
    if((T->leftchild==NULL && T->rightchild==NULL) || (T->rightchild!=NULL && T->leftchild!=NULL))
    cout<<"(";
    if(T->rightchild==NULL)
    cout<<")";
        cout<<T->data<<" ";
     //   if(T->leftchild!=NULL)
        preorder(T->leftchild);
   //     if(T->rightchild!=NULL)
        preorder(T->rightchild);
   //     else
   //     cout<<")";
}

void inorder(BSTPTR T){
    if(T->data==0)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        else
        cout<<"(";
        cout<<T->data<<" ";
        if(T->rightchild!=NULL)
        inorder(T->rightchild);
        else
        cout<<")";
    
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
    if(T==NULL)
    return;
    cout<<T->data<<" ";
    inorder(T);cout<<endl;
    printer(T->leftchild);
    printer(T->rightchild);
}

void postorder(BSTPTR T,int i,int z){

    if(z==9)
    return;
        if(T->leftchild!=NULL)
        postorder(T->leftchild,i,z);
        if(T->rightchild!=NULL)
        postorder(T->rightchild,i,z);
        z++;
       // cout<<z<<endl;
        if(z>i)
        cout<<T->data<<" ";
        
}

void printer(BSTPTR T,int i,int j)
{
    if(i==9)
    return;
 //   cout<<i<<" ";
   // cout<<"check";
    postorder(T,i,j);
    cout<<endl; 
    i++;
    printer(T,i,j);
}

int main(){
      
    BSTPTR S=NULL;

    make(S);
    int j=0;
    preorder(S);
    return 0;
}