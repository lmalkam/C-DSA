#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};
typedef trnode* LPTR;


void print(LPTR L,int counter){
    if(counter==0)
    return;
    if(L->data>=1 && L->data<=15){
   // cout<<L->data;
    cout<<"B";
    }
    if(L->data>15 && L->data<=30){
   // cout<<L->data;
    cout<<"A";}
    return print(L->next,counter-1);
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


void josephus(LPTR &L,LPTR R,int counter,int n,int num,int i){
    if(counter==0)
    return;
    //cout<<"checl";
    if(n==0){
        cout<<L->data<<" ";
        rdelete(R,R->data);
        L->data=i;
        return josephus(L->next,R->next-1,num-1,num,i+1);
    }
    else
    return josephus(L->next,R->next,n-1,num,i);
}

int main(){
	

    LPTR P;
    int m,x;
    int n=x;
    cin>>m>>x;
    P=new(trnode);
    P->data=1;
    P->next=NULL;
    for(int i=2;i<=m;i++){
    addend(P,i);}
    
    int coun=m;
    circle(P,P);
    int i=1;

    josephus(P,P,coun,x-1,x,i);

    cout<<"check";

    print(P,m);
    
    return 0;
}                   

