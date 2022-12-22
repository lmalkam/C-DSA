#include <iostream>
using namespace std;

struct gtNode
{
    char data;
    gtNode* fc=NULL;
    gtNode* ns=NULL;
};

typedef struct gtNode* GTPTR;

struct stack{
  int s=50;
  int f=-1;
  int r=-1;
  GTPTR elements[50];
};

void eque(stack &Q, GTPTR x){
    if ((Q.r+1)%Q.s==Q.f) cout << "Queue is Full";
    else{
        if (Q.r==-1){
            Q.r=0; Q.f=0;
        }
        else Q.r = (Q.r+1)%Q.s;
        Q.elements[Q.r]=x;
    }
}

GTPTR dequeue (stack &Q){
    GTPTR t;
    if (Q.f==-1) return NULL;
    else{
        t = Q.elements[Q.f];
        if (Q.f==Q.r){
            Q.f=-1; Q.r=-1;
        }
        else Q.f = (Q.f+1)%Q.s;
        return t;
    }
}

void createGT(GTPTR &T)
{
    char n;
    cin>>n;
    if (n=='.') return;
    T=new(gtNode);
    T->data=n;
    createGT(T->fc);
    createGT(T->ns);
}

GTPTR findParent(stack &Q, char k)
{
    GTPTR T = dequeue(Q);
    GTPTR P=T->fc;
    while (P!=NULL)
    {
        if (P->data==k) return T;
        eque(Q,P);
        P=P->ns;
    }
    return findParent(Q,k);
}

bool children(GTPTR T, char k)
{
    GTPTR P = T->fc;
    while (P!=NULL)
    {
        if (P->data==k) return true;
        P=P->ns;
    }
    return false;
}

GTPTR grandparent(stack &Q, char k)
{
    GTPTR T=dequeue(Q);
    GTPTR F = T->fc;
    eque(Q,F->fc);
    GTPTR P = T->fc;
    while (F!=NULL)
    {
        if (children(F,k)) return P;
        F=F->ns;
    }
    return grandparent(Q,k);
}
void printChildren(GTPTR T, char k)
{
    GTPTR C = T->fc;
    while (C!=NULL)
    {
        cout << k << " " << C->data << endl;
        C=C->ns;
    }
}

void findcousin(stack &Q1, stack&Q2, char k)
{
    GTPTR P = findParent(Q1,k);
    GTPTR GPF = grandparent(Q2,P->data);
    while (GPF!=NULL)
    {
        GTPTR F = GPF->fc;
        while (F!=NULL)
        {
            if (F!=P) 
            printChildren(F,k);
            F=F->ns;
        }
        GPF=GPF->ns;
    }
}

int main()
{
    GTPTR T;
    createGT(T);
    stack Q1,Q2;
    eque(Q1,T);
    eque(Q2,T);
    char k;
    cin>>k;
    findcousin(Q1,Q2,k);
}


/*
INPUT
ABHN.O..I.J..C.D.EKP..LQ...F.GM....
P
*/