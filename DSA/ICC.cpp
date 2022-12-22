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

void join(LPTR L,LPTR R,int k){
	
	while(L->data!=k){
    	L=L->next;
    }
    
    while(R->next!=NULL){
    	R=R->next;
    }
    
    R->next=L;
    
}

void pushall(LPTR L,LPTR R,stack &s,stack &s2){
    
    while(L!=NULL){
        push(s,L->data);
        L=L->next;
    }
    
    while(R!=NULL){
        push(s2,R->data);
        R=R->next;
    }
    
}

int middle(stack s,stack s2){

    int t1,t2,temp;
    while(s.top!=-1){
        t1=pop(s);
        t2=pop(s2);
        if(t1!=t2)
        break;
        temp=t1;
    }
    return temp;
}
int main(){
	
	int k;
	cin>>k;

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
    
    R=new(trnode);
    cin>>n;
    R->data=n;
    R->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(R,n);
    cin>>n;
    }
    
    stack s;s.top=-1;
    stack s2;s2.top=-1;
    
    join(P,R,k);
    
    pushall(P,R,s,s2);
    
    
    int temp=middle(s,s2);
    cout<<temp<<endl;

    while(s2.top!=-1)
    pop(s2);
    int t;
    while(t!=temp){
        t=pop(s);
        push(s2,t);
    }

    while(s2.top!=-1)
    cout<<pop(s2)<<" ";
    
    return 0;
}                   

