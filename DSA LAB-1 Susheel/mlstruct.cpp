#include<iostream>
using namespace std;

struct mlnode
{
    int data;
    mlnode* dptr;
    mlnode *next;
};

typedef mlnode* MLPTR;

MLPTR findend(MLPTR L){
    while(L->next!=NULL)
    L=L->next;
    return L;
}

void print(MLPTR L){
    if(L==NULL){
    return;}

  
    if(L->data==1)
        print(L->dptr);

    else
      cout<<L->data<<" ";
    return print(L->next);
}

void addend(MLPTR &L,int n){
   
   if(L==NULL){
       L=new(mlnode);
       L->data=n;
       L->next=NULL;
   }
   else{
    MLPTR T,E;
    T=new(mlnode);
    T->data=n;
    T->next=NULL;
    E=findend(L);
    E->next=T;
   }
    
}

void adding(MLPTR &L,int n){
    if(n==1){
        addend(L,n);
        cin>>n;
        MLPTR T=NULL,E;
        T=new(mlnode);
        T->data=n;
        E=findend(L);
        E->dptr=T;
        cin>>n;
        while(n!=-1){
            adding(T,n);
            cin>>n;
        }
    }
    else if(n==-1){
        return;
    }
    else if (n!=0)
    addend(L,n);
}

int main(){

    MLPTR P,R;
    int n;cin>>n;
    P=new(mlnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-2){
    adding(P,n);
    cin>>n;
    }

    print(P);

    return 0;
}