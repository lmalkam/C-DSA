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

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
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

void palindrome(LPTR l1, LPTR &l2, int &flag)
{
    if (l1 == NULL)
    {
        return;
    }
    else
    {
        int t = l1->data;
        palindrome(l1->next, l2, flag); 
        // cout<<t<<" "<<l2->data<<endl; 
        if(t!=l2->data) 
        { flag=0; 
        } 
        l2=l2->next; 
        } 
     }


int search(LPTR L,int key){
    if(L==NULL)
    return 0;
    else if(key==L->data)
    return 1;
    return search(L->next,key);
}

  void duplicates2(LPTR &L){
    if(L==NULL){
    return;}

    if(search(L->next,L->data)==1)
    {
        rdelete(L->next,L->data);
        return duplicates2(L);
    }

    return duplicates2(L->next);
  }

int main(){

    LPTR P;int n;LPTR R;int k;int flag=1;
 /*  cin>>n;
    P=new(node);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }palindrome(P,P,flag);
    cout<<flag;cout<<endl;*/

    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    duplicates2(P);
    print(P);
    cout<<endl;


    return 0;
}     