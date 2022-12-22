#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};
typedef trnode* LPTR;
struct stack
{
    int top;
    int sta[100];
};

void push(stack &s,int x)
{
    s.top++;
    s.sta[s.top]=x;
}
int pop(stack &s)
{
    return (s.sta[s.top--]);
}

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

LPTR middle(LPTR i,LPTR j,int z){
    if(j==NULL)
    return i;
    if(z==2)
    return middle(i->next,j,0);
    return middle(i,j->next,z+1);
}

void pushall(LPTR L,stack &s){
    while(L!=NULL){
        push(s,L->data);
        L=L->next;
    }
}

bool palindrome(LPTR &L,LPTR Q,stack &s){
    while(L!=middle(Q,Q,0)){
        if(L->data!=pop(s))
        return 0;
        L=L->next;
    }
    return 1;
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

    stack s;s.top=-1;

    R=middle(P,P,0);
    pushall(R,s);
  cout<<palindrome(P,P,s);
    return 0;
}                   

