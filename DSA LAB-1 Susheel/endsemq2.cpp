#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild=NULL;
    int data;
    trnode *rightchild=NULL;
    int x;
    int y;
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
        cout<<"0 ";
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


void assignxy2(BSTPTR T,int innumb,int lev)
{
    if(T!=NULL){
   // cout<<innumb<<lev;
    T->x=innumb;
    T->y=lev;
    if(T->leftchild!=NULL);
    assignxy2(T->leftchild,innumb-1,lev+1);
    if(T->rightchild!=NULL)
    assignxy2(T->rightchild,innumb+1,lev+1);
    }

}

void getmaxminy(BSTPTR T,int &max,int &min)
{
    if(T!=NULL)
    {
        if(T->y>max)
        max=T->y;
        if(T->y<min)
        min=T->y;
        getmaxminy(T->leftchild,max,min);
        getmaxminy(T->rightchild,max,min);
    }
}

void check(BSTPTR T,int n,bool &flag)
{
    if(T!=NULL)
    {
        if(T->y<=n)
        {
            if(T->leftchild==NULL || T->rightchild==NULL)
            flag=false;
        }
        check(T->leftchild,n,flag);
        check(T->rightchild,n,flag);
    }
}

void mirror(BSTPTR &M,BSTPTR T)
{
    M=new(trnode);
    M->data=T->data;
    if(T->rightchild!=NULL)
    mirror(M->leftchild,T->rightchild);
    if(T->leftchild!=NULL)
    mirror(M->rightchild,T->leftchild);
}

int main(){
      
    BSTPTR S=NULL;

    make(S);

    int i=0,j=0;

    assignxy2(S,i,j);
    int maxy=-999;int miny=999;
    getmaxminy(S,maxy,miny); 
    i=0;bool flag=true;
    check(S,maxy-2,flag);

    if(flag)
    cout<<"";
    else
    {
        cout<<"NO";
        return 0;
    }

    BSTPTR M=NULL;

    mirror(M,S);

    preorder(M);

    return 0;
}
/*
ABD#HLQ###M##E##CFIN####GJP#RS##T#UV#X#YZ####K###
*/
     