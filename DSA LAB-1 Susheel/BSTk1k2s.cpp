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


void printer(BSTPTR T){
    if(T==NULL){
    return;}
    cout<<T->data<<" ";
    inorder(T);cout<<endl;
    printer(T->leftchild);
    printer(T->rightchild);
}

void search(BSTPTR T1, BSTPTR T2,int s)
{
    while (T1==NULL && T2==NULL)
    {
        if(T1->data+T2->data<s)
        {
            if(T1->rightchild->data+T2->rightchild->data<=s)
            {
                T1=T1->rightchild;
                T2=T2->rightchild;
                if(T1->data+T2->data==s)
                cout<<T1->data<<" "<<T2->data<<endl;
            }
            if(T1)


        }
    }
    

}

int main(){
      
    BSTPTR S=NULL;
    int n;cin>>n;
    while(n!=-1){
        insert(S,n);
        cin>>n;
    }

    BSTPTR T=NULL;
    cin>>n;
    while(n!=-1){
        insert(T,n);
        cin>>n;
    }

    int s;
    cin>>s;

    search(S,T,s);

    
    

     return 0;
}