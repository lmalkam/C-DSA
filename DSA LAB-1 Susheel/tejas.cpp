#include <iostream>
using namespace std;
struct btnode
{
	btnode* lc;
	int data;
	btnode* rc;
};
typedef btnode* btptr;
void insert(btptr &T,int n)
{
	if(T==NULL){
		T=new(btnode);
		T->data=n;
		T->lc=NULL;
		T->rc=NULL;
	}
	else{
		if(n>T->data){
			insert(T->rc,n);
		}
		else insert(T->lc,n);
	}
}
int max(btptr T,int &maxn)
{
	if(T==NULL) return maxn;
	else{
		if(T->data>maxn) maxn=T->data;
		cout<<"#";
		max(T->lc,maxn);
		max(T->rc,maxn);
	}
}
void find(btptr &T,int k)
{
    while(T->data!=k)
    {
        if(k<T->data)
        T=T->lc;
        else
        T=T->rc;
    }
}
void del(btptr &T,int k)
{
	btptr temp=NULL;
    temp=T;
    find(temp,k);
	cout<<temp->data;
	if(temp->lc==NULL && temp->rc==NULL){
		temp->data=0;
		return;
	}
	else{
		int maxn=0;
		max(temp->lc,maxn);
		temp->data=maxn;
		del(temp,k=maxn);
	}
}
void preorder(btptr T)
{
	if(T!=NULL){
		preorder(T->lc);
        cout<<T->data<<" ";
		preorder(T->rc);
	}
}
int main()
{
	btptr T=NULL;
	int n;
	cin>>n;
	while(n!=-1){
		insert(T,n);
		cin>>n;
	}
	preorder(T);
	int k;
	cin>>k;
	cout<<"&";
	del(T,k);
	preorder(T);
	return 0;
}
/*
18 11 45 9 15 36 72 5 12 30 63 7 3 -1
11
45
18
-1
*/