#include<iostream>
using namespace std;

struct trnode
{
    trnode* nextsib;
    char data;
    trnode *fc;
    int x,y;
};

typedef trnode* TPTR;



void make(TPTR &T)
{

    char c;cin>>c;
	if(c=='.'){
		return;
    }
	T=new(trnode);
	T->data=c;
    T->fc=NULL;
    T->nextsib=NULL;
	make(T->fc);
	make(T->nextsib);
}

void preorder(TPTR T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        preorder(T->fc);
        preorder(T->nextsib);
    }
}

void print(TPTR T,TPTR par,char n)
{
    while(T!=NULL)
    {
        if(T->data==par->data)
        break;
        T=T->fc;
    }

    while(T!=NULL)
    {
        if(T->data!=n)
        cout<<T->data<<" ";
        T=T->nextsib;
    }
}

TPTR findfistsib(TPTR T,char ch)
{
    if(T==NULL)
    return NULL;

    TPTR L=T;
    while(L!=NULL)
    {
        if(L->data==ch)
        return T;
        L=L->nextsib;
    }

    return findfistsib(T->fc,ch);
}

int main(){
      
    TPTR S=NULL;

    make(S);
    char target;
    cin>>target;
    TPTR par=findfistsib(S,target);
    print(S,par,target);


     return 0;
}
