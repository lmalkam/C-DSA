#include<iostream>
using namespace std;
struct trnode
{
	struct trnode *lc;
	int data;
	struct trnode *rc;
};
typedef struct trnode *BSTPTR;

void insert(BSTPTR &T,int k)
{
	if (T==NULL)
	{
		T=new(trnode);
		T->data=k;
		T->lc=NULL;
		T->rc=NULL;
	}
	else
	{
		if(k>T->data)
		insert(T->rc,k);
		else
		insert(T->lc,k);
	}
}
void lc_ascending(BSTPTR T)
{
	if(T!=NULL)
	{
		lc_ascending(T->lc);
		cout<<T->data<<" ";
		lc_ascending(T->rc);
	}
}
void rc_descending(BSTPTR T)
{
	if(T!=NULL)
	{
	
	rc_descending(T->rc);
	cout<<T->data<<" ";
	rc_descending(T->lc);
   }
}
int main()
{
    BSTPTR T=NULL;	
	int k;
	cin>>k;
	while(k!=-1)
	{
		insert(T,k);
		cin>>k;
	}
	lc_ascending(T->lc);
	cout<<"/"<<endl;
	cout<<T->data<<"/"<<endl;
	rc_descending(T->rc);
	cout<<"/"<<endl;
}