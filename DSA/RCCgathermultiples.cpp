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

void reverseprint(LPTR L){
    if(L==NULL)
    return;
    reverseprint(L->next);
    cout<<L->data<<" ";
}

void rdelete(LPTR &L,int k){
    if(k==L->data){
        L=L->next;
        return;
    }
    LPTR X=L;
    while(X!=NULL){
    if(X->next->data==k){
        X->next=X->next->next;
    break;
    }
    X=X->next;
    }
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
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

int search(LPTR L,int key){
    if(L==NULL)
    return 0;
    else if(key==L->data)
    return 1;
    return search(L->next,key);
}

void addfront(LPTR &L,int n)
{
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=L;
    L=T;
}

void remove(LPTR &L,int n,int count){
    if(count==0)
    return;

    if(L->data%n==0){
        int t=L->data;
         addend(L,t);
         rdelete(L,t);
        return remove(L,n,count-1);
    }
    else
    return remove(L->next,n,count-1);
}

int main(){

    LPTR P;
    int n;P=NULL;
    cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    int coun=count(P);

    int n1=9;
    remove(P,n1,coun);
    n1=11;
    remove(P,n1,coun);
    n1=13;
    remove(P,13,coun);

    print(P);

    
     return 0;
}