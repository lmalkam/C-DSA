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
        cout<<T->data;
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
    else{
        cout<<"#";
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

void construct(BSTPTR &T,char dlr[],char ldr[],int start,int end)
{
    
    static int i=0;
    if(start>end)
    return;
    T=new(trnode);
    T->data=dlr[i];
    T->leftchild=T->rightchild=NULL;
    int ind=search(ldr,dlr[i++]);
    construct(T->leftchild,dlr,ldr,start,ind-1);
    construct(T->rightchild,dlr,ldr,ind+1,end);
    
}

int main(){

    char dlr[100];
    int i=0;
    cin>>dlr[i];
    while(dlr[i]!='#')
    {
        i++;
        cin>>dlr[i];
    }
    int n=i;i=0;

    char ldr[100];

    cin>>ldr[i];
    while(ldr[i]!='#')
    {
        i++;
        cin>>ldr[i];
    }
    int m=i;
    BSTPTR S=NULL;

    construct(S,dlr,ldr,0,m-1);
    preorder(S);

     return 0;
}