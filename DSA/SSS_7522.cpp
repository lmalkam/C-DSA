#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *next;
};


typedef trnode* LPTR;

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

void print(LPTR L){
    if(L==NULL)
    return;
    cout<<L->data<<" ";
    return print(L->next);
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        c++;
        L=L->next;
    }
    return c;
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

LPTR uni(LPTR L1,LPTR L2,LPTR L3){

    if(L1==NULL and L2==NULL)
    return L3;
    if(L1==NULL)
    {
        addend(L3,L2->data);
        return uni(L1,L2->next,L3);
    }
    if(L2==NULL)
    {
        addend(L3,L1->data);
        return uni(L1->next,L2,L3);
    }
    if(L1->data==L2->data){
        addend(L3,L1->data);
        return uni(L1->next,L2->next,L3);
    }
    if(L1->data<L2->data){
    addend(L3,L1->data);
    return uni(L1->next,L2,L3);
    }
    if(L1->data>L2->data){
    addend(L3,L2->data);
    return uni(L1,L2->next,L3);}

}

int search(LPTR L,int key){
    if(L==NULL)
    return 0;
    else if(key==L->data)
    return 1;
    return search(L->next,key);
}

LPTR uni2(LPTR L1,LPTR L2,LPTR L3){

    if(L1==NULL and L2==NULL)
    return L3;
    
    if(L1==NULL)
    {
        if(search(L3,L2->data)==1)
        return uni2(L1,L2->next,L3);
        else
        addend(L3,L2->data);
        return uni2(L1,L2->next,L3);
    }

    addend(L3,L1->data);
    return uni2(L1->next,L2,L3);

}

LPTR intersect(LPTR L1,LPTR L2,LPTR L3){

    if(L1==NULL and L2==NULL)
    return L3;
    if(L1==NULL)
        return intersect(L1,L2->next,L3);
    
    if(L2==NULL)
        return intersect(L1->next,L2,L3);

    if(L1->data==L2->data){
        addend(L3,L1->data);
        return intersect(L1->next,L2->next,L3);
    }
    if(L1->data<L2->data){
    return intersect(L1->next,L2,L3);}
    
    if(L1->data>L2->data)
    return intersect(L1,L2->next,L3);
}

LPTR intersect2(LPTR L1,LPTR L2,LPTR L3){

    while(L1!=NULL){
        if(search(L2,L1->data)==1)
        addend(L3,L1->data);
        L1=L1->next;
    }

    return L3;
}


LPTR diff(LPTR L1,LPTR L2,LPTR L3){

    if(L1==NULL and L2==NULL)
    return L3;
    if(L1==NULL)
        return diff(L1,L2->next,L3);
    
    if(L2==NULL){
        addend(L3,L1->data);
        return diff(L1->next,L2,L3);}

    if(L1->data==L2->data){
        return diff(L1->next,L2->next,L3);
    }
    if(L1->data<L2->data){
        addend(L3,L1->data);
    return diff(L1->next,L2,L3);}
    
    if(L1->data>L2->data)
    return diff(L1,L2->next,L3);
}

LPTR diff2(LPTR L1,LPTR L2,LPTR L3){

    while(L1!=NULL){
        if(search(L2,L1->data)!=1)
        addend(L3,L1->data);
        L1=L1->next;
    }

    return L3;
}
int main(){
      

   LPTR L1;
    int n;cin>>n;
    L1=new(trnode);
    L1->data=n;
    L1->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L1,n);
    cin>>n;
    }

    LPTR L2;
    cin>>n;
    L2=new(trnode);
    L2->data=n;
    L2->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L2,n);
    cin>>n;
    }
    LPTR L3;
    L3=NULL;
    L3=uni(L1,L2,L3);
    print(L3);
    cout<<endl;
    L3=NULL;
    L3=intersect(L1,L2,L3);
    print(L3);
    L3=NULL;
    cout<<endl;
    L3=diff(L1,L2,L3);
    print(L3);
    cout<<endl;

    LPTR L4;
    cin>>n;
    L4=new(trnode);
    L4->data=n;
    L4->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L4,n);
    cin>>n;
    }

    LPTR L5;
    cin>>n;
    L5=new(trnode);
    L5->data=n;
    L5->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L5,n);
    cin>>n;
    }
    L3=NULL;

    L3=uni2(L4,L5,L3);
    print(L3);
    cout<<endl;
    L3=NULL;
    L3=intersect2(L4,L5,L3);
    print(L3);
    L3=NULL;
    cout<<endl;
    L3=diff2(L4,L5,L3);
    print(L3);
    cout<<endl;
     return 0;
}