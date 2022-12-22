#include <iostream>
using namespace std;

struct gtNode
{
    char data;
    gtNode* fc=NULL;
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
    if (n=='#') return;
    T=new(gtNode);
    T->data=n;
    T->ns=T->fc=NULL;
    createGT(T->fc);
    createGT(T->ns);
}

void levelorder(GTPTR T,stack &q,GTPTR X)
{
    eque(q,T);
    eque(q,X);
    while(q.r!=-1)
    {
        GTPTR A=dequeue(q);
        if(A==NULL)
        {
            if(q.r==-1){
                cout<<"/"<<endl;
            return;
            }
            else
            {
                cout<<"/"<<endl;
                eque(q,X);
                continue;
            }
        }
        else
        {
            cout<<A->data<<" ";
            if(A->fc!=NULL)
            eque(q,A->fc);
            A=A->fc;
            GTPTR L=A;
            while(L->ns!=NULL)
            {
                eque(q,L->ns);
                L=L->ns;
            }
        }
    }
}



int main()
{
    GTPTR T;
    createGT(T);
    stack Q1;
    GTPTR X=NULL;
    levelorder(T,Q1,X);
}


/*
INPUT
ABHN.O..I.J..C.D.EKP..LQ...F.GM....
P
*/