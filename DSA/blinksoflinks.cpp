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

int middle(LPTR i,LPTR j,int z){
    if(j==NULL)
    return i->data;
    if(z==2)
    return middle(i->next,j,0);
    return middle(i,j->next,z+1);
}

int last(LPTR L){
    if(L->next==NULL)
    return L->data;

    return last(L->next);
}

bool palindrome(LPTR &L){
    if(L->data==middle(L,L,0))
    return 1;

    if(L->data==last(L)){
        rdelete(L,L->data);
        rdelete(L,last(L));
        return palindrome(L);
    }
    else{
    return 0;}
}

void duplicates(LPTR &L){
    if(L->next==NULL)
    return;
    if(L->data==L->next->data)
    {
        rdelete(L,L->data);
        return duplicates(L);
    }
    return duplicates(L->next);
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
        return duplicates2(L->next);
    }

    return duplicates2(L->next);
}
void segregate(LPTR &L,int counter,int n){
    
    if(counter==n)
    return;

    if(L->data%2!=0){
        addend(L,L->data);
        rdelete(L,L->data);
        return segregate(L,counter+1,n);
    }

    return segregate(L->next,counter+1,n);
}

int first(LPTR L){
    return L->data;
}

LPTR previous(LPTR L,int n){
    if(L->next->data==n)
    return L;
    return previous(L->next,n);
}

void reverse(LPTR L,LPTR &R){
    if(L==NULL)
    return;
    int t=L->data;
    reverse(L->next,R);
    addend(R,t);
    return;
}

bool check(LPTR L,LPTR R,LPTR S,int counter){
    if(R==NULL)
    return 1;
    if(L==NULL)
    return 0;
    if(L->data==R->data){
        return check(L->next,R->next,S,counter+1);
    }
    return check(L->next,S,S,0);
}

LPTR linky(LPTR L,LPTR R,LPTR Q){
    if(L==NULL && R==NULL)
    return Q;
    if(L==NULL){
        addend(Q,R->data);
        return linky(L,R->next,Q);
    }
    if(R==NULL){
        addend(Q,L->data);
        return linky(L->next,R,Q);
    }
    addend(Q,L->data);
    addend(Q,R->data);
    return linky(L->next,R->next,Q);
}

LPTR insertion(LPTR L){
    LPTR x=L,y=L;
    while(x!=NULL){
        y=x->next;
        while(y!=NULL){
            if(x->data>y->data){
                int t=x->data;
                x->data=y->data;
                y->data=t;
            }
            y=y->next;
        }
        x=x->next;
    }
    return L;
}
LPTR swapk(LPTR L,int k){

    LPTR x=L,y=L;

    for(int i=0;i<k-1;i++)
    x=x->next;
    for(int i=0;i<count(L)-k;i++)
    y=y->next;
    int t=x->data;
    x->data=y->data;
    y->data=t;
    return L;
}
int main(){

    LPTR P;int n;LPTR R;int k;
   cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }cout<<palindrome(P);cout<<endl;

    
   P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    duplicates(P);
print(P);cout<<endl;


    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
   duplicates2(P);
print(P);cout<<endl;


    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    duplicates2(P);
    print(P);cout<<endl;;


   P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    segregate(P,0,count(P));
    print(P);cout<<endl;


    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    P=insertion(P);
    print(P);cout<<endl;

    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    R=NULL;
    reverse(P,R);
    print(R);cout<<endl;


    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    cin>>k;
    P=swapk(P,k);
    print(P);cout<<endl;

    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    R=NULL;
    cin>>n;
    while(n!=-1){
    addend(R,n);
    cin>>n;}
    cout<<check(P,R,R,0);cout<<endl;
    

    P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;}
    R=NULL;
    cin>>n;
    while(n!=-1){
    addend(R,n);
    cin>>n;}
    LPTR Q;
    Q=NULL;
    Q=linky(P,R,Q);
    print(Q);

    return 0;

}                   
