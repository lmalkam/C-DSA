#include <iostream>
using namespace std;

struct btnode
{
	btnode* lc;
	int data;
	int x;
	btnode* rc;
};

struct node
{
	btnode* bt;
	node *next;
};

typedef btnode* BTPTR;
typedef node* LPTR;

LPTR findEnd(LPTR L)
{
	if(L->next==NULL)
		return L;
	return findEnd(L->next);
}

void addEnd(LPTR &L, BTPTR Tree)
{
	if(L!=NULL)
	{
		LPTR T,E;
		T=new(node);
		T->bt = Tree;
		T->next = NULL;
		E = findEnd(L);
		E->next = T;
	}
	else
	{
		L=new(node);
		L->bt=Tree;
		L->next=NULL;
	}
}

void CreateBT(BTPTR &T)
{
    int n;
    cin>>n;
    if(n==0)
        return;
    T=new(btnode);
    T->data=n;
    T->x=0;
    T->lc=T->rc=NULL;
    CreateBT(T->lc);
    CreateBT(T->rc);
}

void CreateLL(LPTR &L)
{
	for(int i=1;i<=5;i++)
	{
		BTPTR T=NULL;
		CreateBT(T);
		addEnd(L,T);
	}
}

void print(BTPTR T)
{
	if(T==NULL)
		return;
	cout<<T->data<<" ";
	print(T->lc);
	print(T->rc);
}

void freqprint(LPTR L,BTPTR tree,int &c,int k)
{
    if(tree==NULL)
    return;
    if(tree->data==k){
        tree->data=0;
    c++;}
    freqprint(L,tree->lc,c,k);
    freqprint(L,tree->rc,c,k);
    if(L->next!=NULL)
    freqprint(L->next,L->next->bt,c,k);
}


int main()
{
	LPTR L=NULL;
	BTPTR tree=NULL;
	CreateLL(L);
	int k;
	cin>>k;
	int c=0;
	int flag=0;
	freqprint(L,L->bt,c,k);
	if(c==0)
	{
		cout<<"-1";
	}
	else
	{
		cout<<c;
	}
}
/*
7 22 5 0 0 45 0 0 10 0 0
42 0  18 10 0 0 35 0 0
63 7 0 0 36 5 0 0 18 0 0 
18 0 27 22 0 0 0 
12 36 0 0 7 85 0 0 52 0 0 
*/