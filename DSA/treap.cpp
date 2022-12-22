#include<iostream>
using namespace std;

struct trnode
{
    trnode* lc;
    char data;
    int data;
    trnode *rc;
};

typedef trnode* TPTR;

void rotateright(TPTR &T)
{
	TPTR t1=T->lc;
	TPTR t2=t1->rc;
	t1->rc=T;
	T->lc=t2;
	T=t1;
}
void rotateleft(TPTR &T)
{
    TPTR t1=T->rc;
    TPTR t2=t1->lc;
    t1->lc=T;
    T->rc=t2;
    T=t1;
}

void insert(TPTR &T,char c,int n){

    if(T==NULL)
    {
        T=new(trnode);
        T->data=c;
        T->data=n;
        T->lc=NULL;
        T->rc=NULL;
    }
    else{
        
        if(int(c)<int(T->data))
        {
            insert(T->lc,c,n);
            if(T->lc!=NULL && T->data<n)
            rotateright(T);
        }
        else{
            insert(T->rc,c,n);
            if(T->rc!=NULL && T->data<n)
            rotateleft(T);
        }
    }
}

void inorder(TPTR T)
{
    if(T!=NULL)
    {
        inorder(T->lc);
        cout<<T->data<<" "<<T->data<<" ";
        inorder(T->rc);
    }
}



int main(){
      
    TPTR S=NULL;
    char c;int n;
    cin>>c>>n;

    while(c!='#'){
        insert(S,c,n);
        cin>>c>>n;  
    }

    inorder(S);


     return 0;
}

/*
ABC.D.E..CG.HRS....JK.L.MP.Q..N....
*/