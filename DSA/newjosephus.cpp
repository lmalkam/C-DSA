#include<iostream>
using namespace std;

struct trnode
{
    char data;
    trnode *next;
};

typedef trnode* LPTR;

void print(LPTR L,int m){
    if(m==0)
    return;
    cout<<L->data<<" ";
    return print(L->next,m-1);
}

LPTR findend(LPTR L){
    while(L->next!=NULL)
    L=L->next;
    return L;
}

void addend(LPTR &L,char n){
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

void addfront(LPTR &L,char n)
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

void circle(LPTR L,LPTR Q){

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


void josephus(LPTR L,int counter,int x,int m){
    if(counter==x*(m/2))
    return;

    if(L->data=='B')
    return josephus(L->next,counter,x,m);
    if(counter%x==0){
        L->data='B';
        return josephus(L->next,counter+1,x,m);
    }

    return josephus(L->next,counter+1,x,m);
}

int main(){
	

    LPTR P;LPTR R;
    char n;
    int m,x;
    cin>>m>>x;
    P=NULL;
    for(int i=1;i<=m;i++){
    addend(P,'A');
    }

    int coun=count(P);
    circle(P,P);

    josephus(P,1,x,m);

    print(P,m);
    
    return 0;
}                   

