#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *right;
    trnode *left;
};

typedef struct trnode *DLPTR;

DLPTR findend(DLPTR D)
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

void print(DLPTR D)
{
    if(D==NULL)
		return;
	else
	{
		cout<<D->data<<" ";
		print(D->right);
	}
}

void addend(DLPTR &D,int x){
    if(D==NULL){
        D = new trnode;
        D->left = NULL;
        D->data = x;
        D->right = NULL;
    }
    else{
        DLPTR E = findend(D);
        E->right = new trnode;
        E->right->left = E;
        E->right->right = NULL;
        E->right->data = x;
    }
}
void addfront(DLPTR &D, int k)
{
    DLPTR T=new(trnode);
    T->left=NULL;
    T->data=k;
    T->right=D;
    D=T;
}
DLPTR find(DLPTR D , int n)
{
	while (D!=NULL)
	{
		if(D->data==n)
		{
			return D;
		}
		D=D->right;	
	}
	return 0;
}
void addbefore(DLPTR &D,int x,int y)
{
    DLPTR T=find(D,y);
    DLPTR L=new(trnode);
    L->data=x;
    T->left->right=L;
    L->right=T;
    L->left=T->left->right;
    T->left=L;
}
void addafter(DLPTR D,int x,int y)
{
    DLPTR T=find(D,y);
    DLPTR L=new(trnode);
    L->data=x;
    T->right->left=L;
    L->left=T;
    L->right=T->right;
    T->right=L;
}
void delfront(DLPTR &D)
{
    DLPTR T=D;
    D=D->right;
    D->left=NULL;
}
void delet(DLPTR &D)
{
    DLPTR T=findend(D);
    T=T->left;
    T->right=NULL;
    
}
void del(DLPTR &D,int x)
{

    if(D->data==x)
    {
        return delfront(D);
    }
    else if(x==findend(D)->data)
    return delet(D);
    else
    {
        DLPTR T=D;
        while(T->data!=x)
        {
            T=T->right;
        }
        T->left->right=T->right;
        T->right->left=T->left;
        T->right=NULL;
        T->left=NULL;
    }
    return;

}

void maxmin(DLPTR L,DLPTR &Q,int min,int max){
    if(Q==NULL)
    return;
    if(L==NULL){
        cout<<min<<" "<<max<<endl;
        del(Q,min);del(Q,max);
        return maxmin(Q,Q,9999,0);
    }
    return maxmin(L->right,Q,min>L->data?min=L->data:min=min,max<L->data?max=L->data:max=max);
}
int main()
{
    int n, x, y;
	cin>>n;
	DLPTR L; 
	L=new(trnode);
    L->right=NULL;
    L->data=n; 
    
	cin>>n;
	while (n!=-1)
	{
		addend(L, n);
		cin>>n;
	}

    maxmin(L,L,9999,0);
	
    return 0;
}