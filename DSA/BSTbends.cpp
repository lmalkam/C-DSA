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


void inorder(BSTPTR T){
    if(T!=NULL)
    {
        inorder(T->leftchild);
        cout<<T->data<<" ";
        inorder(T->rightchild);
    }
}

void bends(BSTPTR T,int left,int right,int &c1,int &c2,int &c3,int &c4)
{
    if(T==NULL){
    return;}

    if(left==1){
        if(T->rightchild!=NULL){
        c2++;
        bends(T->rightchild,0,0,c1,c2,c3,c4);}
        if(T->leftchild!=NULL){
            c1++;
        bends(T->leftchild,0,0,c1,c2,c3,c4);}
        return;
    }

    if(right==1){
        if(T->leftchild!=NULL){
            c4++;
        bends(T->leftchild,0,0,c1,c2,c3,c4);}

        if(T->rightchild!=NULL){
              c3++;
        bends(T->rightchild,0,0,c1,c2,c3,c4);}
        return;
    }

    bends(T->leftchild,left+1,right,c1,c2,c3,c4);
    bends(T->rightchild,left,right+1,c1,c2,c3,c4);

}

int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    
    int c1=0,c2=0,c3=0,c4=0;


    bends(S,0,0,c1,c2,c3,c4);
    cout<<c1<<c2<<c3<<c4;

     return 0;
}