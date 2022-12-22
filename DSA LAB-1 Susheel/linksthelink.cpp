#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};
typedef trnode* LPTR;

struct nod
{
    trnode* next1;
    trnode* next2;
    nod* next3;
};

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

LPTR find(LPTR L,int key){
	
	if(L->data==key)
	return L;
	
	return find(L->next,key);
}

void loop(LPTR L,int key){
    
    LPTR X=L;
    while(L->next!=NULL){
        L=L->next;
    }
    L->next=find(X,key);
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
}

nod* findend2(nod* L){
    while(L->next3!=NULL)
    L=L->next3;
    return L;
}

void addend2(nod* L,LPTR n1,LPTR n2){

    if(L==NULL){
       L=new(nod);
       L->next1=n1;
       L->next2=n2;
       L->next3=NULL; 
    }
    else{
    nod* T;nod* E;
    T=new(nod);
    T->next1=n1;
    T->next2=n2;
    T->next3=NULL;
    E=findend2(L);
    E->next3=T;
    }
}


void sort(LPTR L1,LPTR L2,LPTR i,LPTR j,nod*SL){

    if(L1==NULL && L2==NULL){
        return;
    }

    if(L1->data<L2->data){
    return sort(L1->next,L2,L1,j,SL);}

    if(L1->data>L2->data){
    sort(L1->next,L2->next,i,L2,SL);
    addend2(SL,i,j);
    return;
    }

}

void print2(nod* L){
    if(L==NULL)
    return;

    print(L->next1);
    print(L->next2);

    return print2(L->next3);

}
int main(){

    LPTR P;LPTR R;
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
    cin>>n;
    while(n!=-1){
    addend(R,n);
    cin>>n;
    }
    nod* SL;
    SL=NULL;

    int coun=count(P);

    sort(P,R,P,R,SL);

    print2(SL);

    
    
    return 0;
}                   

