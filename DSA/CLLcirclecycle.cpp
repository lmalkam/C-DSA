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

void circle(LPTR &L,LPTR Q){

    if(Q->next==NULL){
        Q->next=L;
        return;
    }
    return circle(L,Q->next);
}
int coun;
void cusprint(LPTR L,int key){
    if(L->data==key){
       cout<<L->data<<" "; 
       cout<<endl;
    return;}
    cout<<L->data<<" ";
    return cusprint(L->next,key);
}

int search(LPTR L,int key,int counter){
    if(counter==0)
    return 0;
    else if(key==L->data)
    return 1;
    return search(L->next,key,counter-1);
}
void cycles(LPTR L,int counter){
    if(counter==0)
    return;
    if(search(L->next,L->data,coun-1)==1){
        cout<<L->data<<" ";
        cusprint(L->next,L->data);
    }
    return cycles(L->next,counter-1);
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
    coun=count(P);
    
    circle(P,P);

    cycles(P,coun);

    return 0;
}                   

