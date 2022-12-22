#include<iostream>
using namespace std;
struct trnode
{
    int data;
    trnode *right;
    trnode *left;
};

typedef struct trnode *DPTR;
DPTR findend(DPTR D)
{
    
 while(D!=NULL)
 {
     if(D->right==NULL)
     {
         return D;
     }
     D=D->right;
 }
}
void print(DPTR D)
{
    if(D==NULL)
		return;
	else
	{
		cout<<D->data<<" ";
		print(D->right);
	}
}
void addend(DPTR &d,int x){
    if(d==NULL){
        d = new trnode;
        d->left = NULL;
        d->data = x;
        d->right = NULL;
    }
    else{
        DPTR e = findend(d);
        e->right = new trnode;
        e->right->left = e;
        e->right->right = NULL;
        e->right->data = x;
    }
}
void delfront(DPTR &D)
{
    DPTR T=D;
    D=D->right;
    D->left=NULL;
}
void delet(DPTR &D)
{
    DPTR T=findend(D);
    T=T->left;
    T->right=NULL;
    
}
void del(DPTR &D,int x)
{
    if(D->data==x)
    {
        delfront(D);
    }
    else if(x==findend(D)->data)
    return delet(D);
    else
    {
        DPTR T=D;
        while(T->data!=x)
        {
            T=T->right;
        }
        T->left->right=T->right;
        T->right->left=T->left;
        T->right=NULL;
        T->left=NULL;
    }

}
void minmax(DPTR &L)
{
    int min = 10000, max = 0, t;
    DPTR T;
    T=L;
    if(L==NULL)
    {
        return;
    }
    else
    {
    while(T!=NULL)
    {
        t=T->data;
        if(t>max)
        {
            max=t;
        }
        
        if(t<min)
        {
            min=t;
        }
        T=T->right;
    }
    cout<<min<<" "<<max<<endl;
    del(L,min);
    del(L,max);
    return minmax(L);
    }
}
int main()
{
    int n, k, x, y;
	cin>>n;
	DPTR L; 
	L=new(trnode);
    L->right=NULL;
    L->data=n; 
    
	cin>>n;
	while (n!=-1)
	{
		addend(L, n);
		cin>>n;
	}
	minmax(L);
	return 0;
}