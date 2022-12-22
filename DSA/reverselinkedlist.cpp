#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};


typedef trnode* LPTR;

void print(LPTR L){
    if(L->next==NULL){
        cout<<L->data;
    return;}
    cout<<L->data<<"->";
    return print(L->next);
}

int delend(LPTR L){
    if(L->next==NULL)
    return L->data;
    if(L->next->next==NULL){
        int t=L->next->data;
        L->next=NULL;
        return t;
    }
    return delend(L->next);
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


LPTR findbefore(LPTR L){
    if(L->next->next==NULL)
    return L;
    return findbefore(L->next);
}

void reverse(LPTR &L){
    if(findend(L)==NULL)
    return;
    LPTR T,E;
    E=findend(L);
    T=findbefore(L);
    E->next=T;
    T->next=NULL;
    reverse(L);
}


int main(){

    int n1,n2;
    cin>>n1;

    LPTR P,R,Q,S;S=NULL;
    P=NULL;int i=0;
    while(n1>0){
    addend(P,n1%10);
    n1=n1/10;i++;
    }
    reverse(P);
    print(P);
    
    
     return 0;
}