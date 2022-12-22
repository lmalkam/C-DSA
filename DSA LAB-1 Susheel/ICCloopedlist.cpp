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

bool checkloop(LPTR i,LPTR j,int z,int key,int count){
    if(j->next->data==key and i->data==key)
    return 1;
    if(count==-1)
    return 0;
    if(z==2)
    return checkloop(i->next,j,0,key,count-1);
    return checkloop(i,j->next,z+1,key,count-1);
}

int length(LPTR L,int count,int k,int z){

    if(z==2)
    return count-1;

    if(k==L->data)
    return length(L->next,count+1,k,z+1);

    if(z==1)
    return length(L->next,count+1,k,z);

    return length(L->next,count,k,z);

}

void deloop(LPTR i,LPTR j,int z,int key,int count){
    if(j->next->data==key and i->data==key){
        j->next=NULL;
    return;}
    if(count==-1)
    return;
    if(z==2)
    return deloop(i->next,j,0,key,count-1);
    return deloop(i,j->next,z+1,key,count-1);

}

int meet(LPTR i,LPTR j,int count,int z){
    if(j->next->data==i->data){
        return i->data;
    }
    if(count==-1)
    return 0;
    if(z==2)
    return meet(i->next,j,count-1,0);
    return meet(i,j->next,count-1,z+1);
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

    int coun=count(P);
    coun=coun+coun/2;
    
    loop(P,k);
    
    cout<<checkloop(P,P,0,k,coun);cout<<endl;

    cout<<length(P,0,k,0)<<endl;

    cout<<meet(P,P,coun,0)<<endl;

    deloop(P,P,0,k,coun);

    print(P);

    
    return 0;
}                   

