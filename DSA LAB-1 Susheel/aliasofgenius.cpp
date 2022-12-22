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

void addend(LPTR L,int n){
    
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=NULL;
    E=findend(L);
    E->next=T;
}

void addfront(LPTR &L,int n)
{
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=L;
    L=T;
}

void addbefore(LPTR &L,int x,int y)
{
    if(y==L->data){
        return addfront(L,x);
    }
    LPTR Temp=L;
    while(Temp->next!=NULL){
    if(Temp->next->data==y){
    LPTR T;
    T=new(trnode);
    T->data=x;
    T->next=Temp->next;
    Temp->next=T;
    break;
    }
    Temp=Temp->next;
    }
}

void addafter(LPTR L,int x,int y){
    if(L==NULL)
    cout<<"NULL";
    while(L!=NULL){
    if(L->data==y){
    LPTR T,E;
    T=new(trnode);
    T->data=x;
    T->next=L->next;
    L->next=T; 
    break;
    } 
    L=L->next;
    }                                           
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

int minimum(LPTR L){
    int min=999;
    while(L!=NULL){
    int t=L->data;
    t<min?min=t:min=min;
    L=L->next;}
    return min;
}

int maximum(LPTR L){
    int max=0;
    while(L!=NULL){
    int t=L->data;
    t>max?max=t:max=max;
    L=L->next;}
    return max;
}

int main(){

    LPTR P;
    int n,k;cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }

    print(P);cout<<endl;
    cin>>k;
    addfront(P,k);
    print(P);
    cout<<endl;
    cin>>k>>n;
    addbefore(P,k,n);
    print(P);
    cout<<endl;
    cin>>k>>n;
    addafter(P,k,n);
    print(P);
    cout<<endl;
    cin>>k;
    rdelete(P,k);
    print(P);
    cout<<endl;
    rdelete(P,minimum(P));
    print(P);
    cout<<endl;
    rdelete(P,maximum(P));
    print(P);
    cout<<endl;
}                   
