#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
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

void search(BSTPTR &C,BSTPTR &P,int x)
{
    while(C->data!=x && C!=NULL)
    {
        P=C;
        if(x<C->data)
        C=C->leftchild;
        else
        C=C->rightchild;
    }
}

void makeheapbst(BSTPTR T,int H[],int &n)
{
    if(T!=NULL)
    {
        makeheapbst(T->leftchild,H,n);
        H[n++]=T->data;
        makeheapbst(T->rightchild,H,n);
    }

}


void print(int H[],int i,int n,int b)
{
    if(i==n){
        cout<<"/";
    return;
    }

    cout<<H[i]<<" ";

    if(i==b-1)
    {
        cout<<"/"<<endl;
        if(2*b<n)
        return print(H,i+1,n,b+b*2);
    }

    return print(H,i+1,n,b);
}

int main(){
      
    BSTPTR S=NULL;
    int n;
    cin>>n;
    while(n!=-1)
    {
        insert(S,n);
        cin>>n;
    }

    int H[100];
    n=0;

    makeheapbst(S,H,n);

    print(H,0,n,1);


     return 0;
}