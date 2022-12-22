#include<iostream>
using namespace std;

struct mlnode
{
    char data;
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
    if(L==NULL || L->data=='{')
    return;

    if(L->data=='{')
        print(L->dptr);
    else
      cout<<L->data<<" ";
    return print(L->next);
}

void addend(MLPTR &L,char n){
   
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

void adding(MLPTR &L,char n){
    if(n=='{'){
        addend(L,n);
        cin>>n;
        MLPTR T=NULL,E;
        T=new(mlnode);
        T->data=n;
        E=findend(L);
        E->dptr=T;
        cin>>n;
        while(n!='}'){
            adding(T,n);
            cin>>n;
        }
        addend(T,n);
        return;
    }
    else
    addend(L,n);
}

int main(){
    MLPTR P,R;
    char n;
    P=NULL;
    cin>>n;
    while(n!='#'){
    adding(P,n);
    cin>>n;
    }
    cout<<"check";
    print(P);
    return 0;
}