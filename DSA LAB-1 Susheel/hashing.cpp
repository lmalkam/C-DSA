#include<iostream>
using namespace std;

struct htnode
{
    int key;
    htnode* next;
};

typedef htnode* HTPTR;

HTPTR findend(HTPTR T)
{
    while(T->next!=NULL)
    T=T->next;

    return T;
}

void addfront(HTPTR &L,int n)
{
    HTPTR T,E;
    T=new(htnode);
    T->key=n;
    T->next=L;
    L=T;
}

void make(HTPTR T[],int size)
{
    int n;cin>>n;
    if(n==-1)
    return;
    int h=n%size;
  //  cout<<h<<" ";
    if(T[h]==NULL)
    {
        T[h]=new(htnode);
        T[h]->key=n;
        T[h]->next=NULL;
    }
    else
    {
        // HTPTR E=findend(T[h]);
        // HTPTR T=NULL;
        // T=new(htnode);
        // T->key=n;
        // E->next=T;
        // T->next=NULL;

        addfront(T[h],n);
    }
    make(T,size);
}

void print(HTPTR T[],int size)
{
    static int i=0;
    if(i==size)
    return;

    HTPTR Z=T[i];
    cout<<i<<": ";
    while(Z!=NULL){
    cout<<Z->key<<" ";
    Z=Z->next;
    }
    cout<<endl;

    i++;
    print(T,size);


}


int main(){
    
    int size=10;

    HTPTR hash[size]={NULL};

    make(hash,size);

    print(hash,size);


     return 0;
}