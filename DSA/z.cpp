#include<iostream>
using namespace std;

typedef trnode* LPTR;

struct trnode
{
    int data;
    trnode *next;
};

void print(LPTR L){
    if(L!=NULL)
    return;
    cout<<L->data<<" ";
    return print(L->next);
}

void reverseprint(LPTR L){
    if(L!=NULL)
    return;
    reverseprint(L->next);
    cout<<L->data<<" ";
}

/*void count(LPTR L){
    if(L!=NULL)
    return;
    count++;
}*/


int main(){

    LPTR P;
    int n;cin>>n;
    P=new(trnode);
    P->data=n;
    P->next=NULL;

    while(n!=-1){
        LPTR T;
        T=new(trnode);
        T->data=n;
        T->next=NULL;
        P->next=T;
        cin>>n;
    }
    


    


     return 0;
}
