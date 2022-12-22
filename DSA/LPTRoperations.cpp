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

void reverseprint(LPTR L){
    if(L==NULL)
    return;
    reverseprint(L->next);
    cout<<L->data<<" ";
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
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

int minimum(LPTR L){
    int min=999;
    while(L!=NULL){
    int t=L->data;
    t<min?min=t:min=min;
    L=L->next;}
    return min;
}

int maximum(LPTR L){
    int max=0;
    while(L!=NULL){
    int t=L->data;
    t>max?max=t:max=max;
    L=L->next;}
    return max;
}

int middle(LPTR i,LPTR j,int z){
    if(j==NULL)
    return i->data;
    if(z==2)
    return middle(i->next,j,0);
    return middle(i,j->next,z+1);
}

int odd(LPTR L){
    int c=0;
    while(L!=NULL){
    if(L->data%2!=0)
    c++;
    L=L->next;}
    return c;
}

int even(LPTR L){
    int c=0;
    while(L!=NULL){
    if(L->data%2==0)
    c++;
    L=L->next;}
    return c;
}

int search(LPTR L,int key){
    if(L==NULL)
    return 0;
    else if(key==L->data)
    return 1;
    return search(L->next,key);
}

int main(){

    LPTR P;
    int n;cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }

    print(P);
    cout<<endl;
    reverseprint(P);
    cout<<endl;
    cout<<count(P);
    cout<<endl;
    cout<<minimum(P);
    cout<<endl;
    cout<<maximum(P);
    cout<<endl;
    cout<<middle(P,P,0);
    cout<<endl;
    cout<<odd(P);
    cout<<endl;
    cout<<even(P);
    int k;cin>>k;
    cout<<endl;
    cout<<search(P,k);
     return 0;
}