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


LPTR reverse2(LPTR &L,LPTR V,LPTR R1,LPTR R2,int j){
	if(V->data!=j){
	     if(R1->next==NULL){
	     L=R1;
         return L;
         }
		reverse2(L,V->next,R1->next,R2->next,j);
		R1->next=R2;
		R2->next=NULL;
	}
    
}

void reverse(LPTR L,int i,int j){
    if(L==NULL)
    return;
    else if(L->data==i)
    {
    L=reverse2(L,L->next,L->next,L, j);
    while(L->data!=j)
    L=L->next;
    return reverse(L->next,i,j);
    }
    else{
        return reverse(L->next,i,j);
    }
}

int main(){

    LPTR P,R;
    int n;cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    R=NULL;
    int i,j;
    cin>>i>>j;
    reverse(P,i,j);
    print(P);
    
     return 0;
}