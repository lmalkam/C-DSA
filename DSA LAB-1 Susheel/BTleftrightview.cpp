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



void leftview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->leftchild!=NULL)
    leftview(T->leftchild,cl+1,lpl);
    if(T->rightchild!=NULL)
    leftview(T->rightchild,cl+1,lpl);
}

void rightview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->rightchild!=NULL)
    rightview(T->rightchild,cl+1,lpl);
    if(T->leftchild!=NULL)
    rightview(T->leftchild,cl+1,lpl);
}

int main(){
      
    BSTPTR S=NULL;

    make(S);

    int i=0,j=-1;

    leftview(S,i,j);
    cout<<endl;i=0;j=-1;
    rightview(S,i,j);
   

     return 0;
}