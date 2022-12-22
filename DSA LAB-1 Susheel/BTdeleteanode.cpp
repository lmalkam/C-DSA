#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

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
        cout<<T->data;
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

BSTPTR N=NULL,P=NULL;

void search(BSTPTR &T,char ch)
{ 
      if(T!=NULL){
        if(T->data==ch){
        N=T;
        return;}
        search(T->leftchild,ch);
        search(T->rightchild,ch);
      }
    
}

BSTPTR deep(BSTPTR T,BSTPTR &P,int curr,int max,char &ch)
{
    if(T!=NULL)
    {
        deep(T->leftchild,T,curr+1,max,ch);
        cout<<T->data<<" ";
        if(curr>max)
        {
            ch=T->data;
            max=curr;
        }
        deep(T->rightchild,T,curr,max,ch);
    }
}
void del(BSTPTR &T,char ch)
{
   
    BSTPTR F=NULL;
    search(T,ch);
    F=N;P=F;
    deep(F,P,-1,-1,ch);
    F->data=ch;
  //  cout<<P->data; 
    search(T,ch);
    F=N;
    F=NULL;
}

int main(){
      
    BSTPTR S=NULL;
    make(S);


    char ch1,ch2;
    cin>>ch1;
    cin>>ch2;;
    del(S,ch1);
    preorder(S);cout<<endl;
    del(S,ch2);
    preorder(S);

     return 0;
}