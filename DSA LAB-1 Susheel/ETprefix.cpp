#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
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

// void make(BSTPTR &T)
// {
// 	char c; cin>>c;
// 	if(c=='#')
// 		return;
// 	T=new(bstnode);
// 	T->data=c;
//     T->leftchild=NULL;
//     T->rightchild=NULL;
// 	make(T->leftchild);
// 	make(T->rightchild);
// }
void left(BSTPTR T){

    if(T==NULL)
    {
        return;
    }
    if(T->leftchild!=NULL){
    cout<<T->leftchild->data<<" ";
    left(T->leftchild);
    }
     if(T->rightchild!=NULL)
    left(T->rightchild);
}

void right(BSTPTR T){

    if(T==NULL)
    {
        return;
    }

    if(T->leftchild!=NULL){
    
    right(T->leftchild);
    }
     if(T->rightchild!=NULL){
         cout<<T->rightchild->data<<" ";
    right(T->rightchild);}
}

void fillin(BSTPTR T,int a[],int &i,int n)
{
    if(T!=NULL){
    if(i<n)
    {
        fillin(T->leftchild,a,i,n);
        T->data=a[i++];
        fillin(T->rightchild,a,i,n);
    }
    }
}

int search(char rdl[],char ch)
{   
    int i=0;
    while(rdl[i]!=ch)
    i++;
  //  cout<<i;

    return i;
}

void construct(BSTPTR &T,char dlr[],char rdl[],int start,int end)
{
    
    static int i=0;
    if(start>end)
    return;
    T=new(trnode);
    T->data=dlr[i];
    T->leftchild=T->rightchild=NULL;
    int ind=search(rdl,dlr[i++]);
    construct(T->leftchild,dlr,rdl,ind+1,end);
    construct(T->rightchild,dlr,rdl,start,ind-1);
    
}

void make(BSTPTR &T)
{
    char ch;cin>>ch;
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*')
    {
        T=new(trnode);
        T->data=ch;
        T->leftchild=T->rightchild=NULL;
    }
    else{
        T=new(trnode);
        T->data=ch;
        T->leftchild=T->rightchild=NULL;
        return;
    }
    make(T->leftchild);
    make(T->rightchild);
}

int eval(BSTPTR T){

    switch (T->data)
    {
    case '-':return eval(T->leftchild)-eval(T->rightchild);
        break;
    case '+':return eval(T->leftchild)+eval(T->rightchild);
        break;
    case '/':return eval(T->leftchild)/eval(T->rightchild);
        break;
    case '*':return eval(T->leftchild)*eval(T->rightchild);
        break;
    default :return T->data-'0';
        break;
    }
}

int main(){

   BSTPTR S=NULL;
   make(S);


   cout<<eval(S);

    

     return 0;
}