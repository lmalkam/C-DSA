#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode* random;
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
        L->random=NULL;
        L->next=NULL;
    }
    else{
    LPTR T,E;
    T=new(trnode);
    T->data=n;
    T->next=NULL;
    T->random->data=0;
    E=findend(L);
    E->next=T;
    }
}


void print(LPTR L){
    if(L==NULL)
    return;
    cout<<L->data<<" ";
    cout<<L->random->data<<" ";
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

void reverse(LPTR &L,LPTR V,LPTR R1,LPTR R2){
	if(V!=NULL){
	     if(R1->next==NULL)
	     L=R1;
		reverse(L,V->next,R1->next,R2->next);
		R1->next=R2;
		R2->next=NULL;
	}
}

void rightmax(LPTR L,LPTR Q,LPTR max){
    if(Q->next==NULL){
        return;
    }

    L->random=max;

    return rightmax(L->next,Q->data<Q->next->data?max=Q:max=max,max);
}

int main(){
      
    LPTR P;
    int n;cin>>n;
    P=new(trnode);
    P->data=n;
    P->random=NULL;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    int x=count(P);

    reverse(P,P->next,P->next,P);
    print(P);

    rightmax(P,P->next,P);

    print(P);
    

     return 0;
}