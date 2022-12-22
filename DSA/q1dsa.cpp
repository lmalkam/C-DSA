#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct dlnode
{
	dlnode* left;
	int data;
	dlnode* right;
};
typedef dlnode* DLPTR;
void dlprint(DLPTR d)
{
	if(d==NULL)
	{
		cout<<endl;
		return;
	}
	else
	{
		cout<<d->data<<" ";
		dlprint(d->right);
	}
}

void dladdfront(DLPTR &d,int x)
{
	if(d==NULL)
	{
		d=new(dlnode);
		d->data=x;
		d->left=d->right=NULL;
		
	}
	else
	{
	
	DLPTR t=new(dlnode);
	t->data=x;
	t->right=d;
	d->left=t;
	t->left=NULL;
	d=t;
	}
}
struct node
{
	int data;
	node* next;
};
typedef node* LPTR;
LPTR findend(LPTR l)
{
	if(l->next==NULL)
	return l;
	else
	return findend(l->next);
}
LPTR addend(LPTR &l, int n)
{
	if(l==NULL)
	{
		l=new(node);
		l->data=n;
		l->next=NULL;
	}
	else
	{
		LPTR t,e;
		t=new(node);
		t->data=n;
		t->next=NULL;
		e=findend(l);
		e->next=t;
	}
}
void createdll(LPTR l,DLPTR &dl)
{
	while(l!=NULL)
	{
		dladdfront(dl,l->data);
		l=l->next;
	}
}
int main()
{
	LPTR L=NULL;
	int k;
	cin>>k;
	while(k!=-1)
	{
		addend(L,k);
		cin>>k;
	}

	DLPTR dl=NULL;
	createdll(L,dl);
	dlprint(dl);
	return 0;
}