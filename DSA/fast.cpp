#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};

typedef trnode* LPTR;

void print(LPTR L){
    if(L==NULL)
    return;
    cout<<L->data<<" ";
    return print(L->next);
}

LPTR findend(LPTR L){
    while(L->next!=NULL)
    L=L->next;
    return L;
}

void addend(LPTR &L,int n){
    if(L==NULL){
        L=new(trnode);
        L->data=n;
        L->next=NULL;
    }
    else{
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=NULL;
    E=findend(L);
    E->next=T;
    }
}

void evenodd(LPTR L,LPTR &L1,LPTR &L2){
    if(L==NULL)
    return;

    if(L->data%2==0){
            addend(L1,L->data);
    }
    else{
            addend(L2,L->data);
        }
    evenodd(L->next,L1,L2);
}

// 3 7 4 6 1 8 5 2 9 -1
int main(){
    LPTR L1,L2,L3;
    L1=new(trnode);int n;
    cin>>n;
    L1->data=n;
    L1->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L1,n);
    cin>>n;
    }
    L2=NULL;L3=NULL;

    evenodd(L1,L2,L3);
    print(L2);cout<<endl;
    print(L3);
    return 0;
}