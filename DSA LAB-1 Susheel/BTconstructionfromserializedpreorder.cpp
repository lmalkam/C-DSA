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
        cout<<T->data;
        preorder(T->leftchild);
        preorder(T->rightchild);
    
}

void inorder(BSTPTR T){
    if(T->data==0)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        cout<<T->data;
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

int main(){
      
    BSTPTR S=NULL;

    make(S);

    preorder(S);
    inorder(S);

     return 0;
}