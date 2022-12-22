#include<iostream>
using namespace std;

struct trnode
{
    trnode* left;
    int data;
    trnode *right;
};
typedef trnode* DLPTR;

void print(DLPTR L){
    if(L==NULL)
    return;
    cout<<L->data<<" ";
    return print(L->right);
}

DLPTR findend(DLPTR L){
    while(L->right!=NULL)
    L=L->right;
    return L;
}

void addend(DLPTR &L,int n){

    if(L==NULL){
        L=new(trnode);
        L->data=n;
        L->right=NULL;
        L->left=NULL;
    }
    else{
    DLPTR T,E;
    T=new(trnode);
    T->data=n;
    T->right=NULL;
    E=findend(L);
    E->right=T;
    T->left=E;
    }
}

void addfront(DLPTR &L,int n)
{
    DLPTR T,E;
    T=new(trnode);
    T->data=n;
    T->right=L;
    L=T;
}


/*void rdelete(DLPTR &L,int k){
    if(k==L->data){
        L=L->right;
        return;
    }
    DLPTR X=L;
    while(X!=NULL){
    if(X->right->data==k){
        X->right=X->right->right;
    break;
    }
    X=X->next;
    }
}*/

void paire(DLPTR L,DLPTR Q,DLPTR S,int key){
    if(Q->right==L || L==Q)
    return;

    if(L==S)
    return paire(L->right,Q,S,key);

    if(Q==S)
    return paire(L,Q->left,S,key);

    if(L->data+Q->data==key)
    {
        cout<<S->data<<" "<<L->data<<" "<<Q->data<<endl;
        return paire(L->right,Q->left,S,key);
    }
    else if(L->data+Q->data>key)
    {
        return paire(L,Q->left,S,key);
    }
    else if(L->data+Q->data<key)
    {
        return paire(L->right,Q,S,key);
    }
}

void triplet(DLPTR L,DLPTR Q,DLPTR S,int key)
{
    if(L==NULL)
    return;

    paire(S,Q,L,key-2*L->data);

    return triplet(L->right,Q,S,key);
}


int main(){
	
    DLPTR P;DLPTR R;
    int n;P=NULL;
    cin>>n;
    while(n!=-1){
    addend(P,n);
    cin>>n;
    }
    R=findend(P);

    int s;cin>>s;

    triplet(P,R,P,s);

    return 0;
}                   

