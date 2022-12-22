#include<iostream>
// #include<cstring>
// #include<cmath>
using namespace std;
struct queue
{
	int size;
	int f;
	int r;
	int elements[100];
};
void enqueue(queue &Q, int x)
{
	if((Q.r+1)%Q.size==Q.f)
	cout<<"Full";
	else
	{
		if(Q.r==-1)
		{
			Q.r=0;
			Q.f=0;
		}
		else
		Q.r=(Q.r+1)%Q.size;
		Q.elements[Q.r]=x;
	} 
}
int dequeue(queue &Q)
{
	int t;
	if(Q.f==-1)
	{
		cout<<"Empty";
		return 0;
	}
	else
	{	t=Q.elements[Q.f];
		if(Q.f==Q.r)
		{
			Q.f=-1;
			Q.r=-1;
		}
		else
		Q.f=(Q.f+1)%Q.size;
		return t;
	}
}
struct btnode
{
	btnode* lc;
	int data;
	btnode* rc;
};
typedef btnode* BTPTR;
void serialisation(BTPTR &T)
{
	int k;
	cin>>k;
	if(k==0 || k==-1)
	return;
	else
	{
		T=new(btnode);
		T->data=k;
		T->lc=NULL;
		T->rc=NULL;
		serialisation(T->lc);
		serialisation(T->rc);
	}
}
int even=0;
void store(BTPTR T,queue &Q)
{
	if(T==NULL)
	return;
	enqueue(Q,T->data);
	if(T->data%2==0)
	even++;
	store(T->lc,Q);
	store(T->rc,Q);
}
void print(queue Q)
{
	int k=0;
	while(Q.f!=-1)
	{
		int t=dequeue(Q);
		if(t%2!=0)
		{
			if(k<even)
			enqueue(Q,t);
			else
			cout<<t<<" ";
		}
		else
		{
			cout<<t<<" ";
			k++;
		}
	}
}
int main()
{
	BTPTR T=NULL;
	serialisation(T);
	
	queue Q;
	Q.f=Q.r=-1;
	Q.size=100;
	store(T,Q);
	print(Q);
	return 0;
}