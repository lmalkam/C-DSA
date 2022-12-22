#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};

typedef trnode* LPTR;

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


void print(LPTR L){
    if(L==NULL)
    return;
    cout<<L->data<<" ";
    return print(L->next);
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
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

LPTR segregate(LPTR &L,int counter,int n){
    
    if(counter==n)
    return L;

    if(L->data%2!=0){
       // cout<<L->data<<" ";
        addend(L,L->data);
        rdelete(L,L->data);
        return segregate(L,counter+1,n);
    }

    return segregate(L->next,counter+1,n);
}

LPTR merge(LPTR L1,LPTR L2,LPTR L3){

    if(L1==NULL and L2==NULL)
    return L3;
    if(L1==NULL)
    {
        addend(L3,L2->data);
        return merge(L1,L2->next,L3);
    }
    if(L2==NULL)
    {
        addend(L3,L1->data);
        return merge(L1->next,L2,L3);
    }
    if(L1->data<L2->data){
    addend(L3,L1->data);
    return merge(L1->next,L2,L3);
    }
    if(L1->data>L2->data){
    addend(L3,L2->data);
    return merge(L1,L2->next,L3);}

}

int main(){
      
   LPTR P;
    int n;cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    int x=count(P);
    segregate(P,0,x);
    print(P);

   LPTR L1;
    cin>>n;
    L1=new(trnode);
    L1->data=n;
    L1->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L1,n);
    cin>>n;
    }

    LPTR L2;
    cin>>n;
    L2=new(trnode);
    L2->data=n;
    L2->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L2,n);
    cin>>n;
    }
    LPTR L3;
    L3=NULL;
    L3=merge(L1,L2,L3);
    print(L3);

     return 0;
}