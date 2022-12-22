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

void rdelete(LPTR &L,int key){
    LPTR T;T=L;
    if(L->data==key)
    {
        while(T->next!=L)
            T=T->next;
        T->next=L->next;
        L=T->next;
      return;
    }

    while(T->next!=L && T->next->data!=key)
    {
        T=T->next;
    }
    if(T->next->data==key)
    {
        T->next=T->next->next;
    }
}

LPTR find(LPTR L,int key){
	
	if(L->data==key)
	return L;
	
	return find(L->next,key);
}

void circle(LPTR &L,LPTR Q){

    if(Q->next==NULL){
        Q->next=L;
        return;
    }

    return circle(L,Q->next);
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
}


void josephus(LPTR L,int counter,int n,int num){
    if(counter==1)
    return;

    if(n==0){
        cout<<L->data<<" ";
        rdelete(L,L->data);
        return josephus(L,counter-1,num,num);
    }
    return josephus(L->next,counter,n-1,num);
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

    int coun=count(P);
    circle(P,P);
    cin>>n;
    
    josephus(P,coun,n-1,n-1);
    
    return 0;
}                   

