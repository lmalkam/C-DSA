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

int delend(LPTR &L){
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

void reverse(LPTR &L,LPTR V,LPTR R1,LPTR R2){
	if(V!=NULL){
	     if(R1->next==NULL)
	     L=R1;
		reverse(L,V->next,R1->next,R2->next);
		R1->next=R2;
		R2->next=NULL;
	}
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



void addition(LPTR L,LPTR R,LPTR &Q,int carry,int counter){

    if(counter==0){
        if(carry==1)
        addend(Q,1);
    return;}
    int t1=delend(L);
    int t2=delend(R);
    if(t1+t2+carry>9){
        addend(Q,(t1+t2+carry)%10);
        return addition(L,R,Q,1,counter-1);
    }
    else{
        addend(Q,t1+t2+carry);
        return addition(L,R,Q,0,counter-1);
    }
}

int main(){

    int n1,n2;
    cin>>n1>>n2;

    LPTR P,R,Q,S;S=NULL;
    P=NULL;int i=0;
    while(n1>0){
    addend(P,n1%10);
    n1=n1/10;i++;
    }
    R=NULL;
    while(n2>0){
    addend(R,n2%10);
    n2=n2/10;
    }
    Q=NULL;

    reverse(P,P->next,P->next,P);
    print(P);cout<<endl;
    reverse(R,R->next,R->next,R);
    print(R);cout<<endl;
    addition(P,R,Q,0,i);
    reverse(Q,Q->next,Q->next,Q);
    print(Q);
     return 0;
}