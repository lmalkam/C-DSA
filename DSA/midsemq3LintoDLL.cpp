#include<iostream>
using namespace std;

struct trnode
{
    int data;
    trnode *right;
    trnode *left;
};

typedef struct trnode *DLPTR;

struct tnode
{
    int pri;
    tnode *next;
};

typedef tnode* LPTR;

void print(LPTR L){
    if(L==NULL)
    return;
    cout<<L->pri<<" ";
    return print(L->next);
}

LPTR findend(LPTR L){
    while(L->next!=NULL)
    L=L->next;
    return L;
}

void addend(LPTR L,int n){
    
    LPTR T,E;
    T=new(tnode);
    T->pri=n;
    T->next=NULL;
    E=findend(L);
    E->next=T;
}

void addfront(LPTR &L,int n)
{
    LPTR T,E;
    T=new(tnode);
    T->pri=n;
    T->next=L;
    L=T;
}

void addbefore(LPTR &L,int x,int y)
{
    if(y==L->pri){
        return addfront(L,x);
    }
    LPTR Temp=L;
    while(Temp->next!=NULL){
    if(Temp->next->pri==y){
    LPTR T;
    T=new(tnode);
    T->pri=x;
    T->next=Temp->next;
    Temp->next=T;
    break;
    }
    Temp=Temp->next;
    }
}

void addafter(LPTR L,int x,int y){
    if(L==NULL)
    cout<<"NULL";
    while(L!=NULL){
    if(L->pri==y){
    LPTR T,E;
    T=new(tnode);
    T->pri=x;
    T->next=L->next;
    L->next=T; 
    break;
    } 
    L=L->next;
    }                                           
}

void rdelete(LPTR &L,int k){
    if(k==L->pri){
        L=L->next;
        return;
    }
    LPTR X=L;
    while(X!=NULL){
    if(X->next->pri==k){
        X->next=X->next->next;
    break;
    }
    X=X->next;
    }
}

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
void delfront(LPTR &L)
{
    LPTR T=L;
    L=L->next;
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


void merge(DLPTR D, LPTR &L,int &count,DLPTR S)
{
    if(L==NULL)return;

    if(D->left==NULL and D->data>L->pri)
    {
        addfront(D,L->pri);
        L=L->next;
        return merge(D,L,count,S);
    }


    if(D->right==NULL and D->data<L->pri)
    {
        addend(D,L->pri);
        L=L->next;
        return merge(D,L,count,S);
    }

    if(D->right!=NULL)
    if(L->pri>D->data){
    count++;
    return merge(D->right,L,count,S);}

    if(D->left!=NULL)
    if(L->pri<D->data && D->left->data<L->pri)
    {
        addbefore(D,L->pri,D->data);
        L=L->next;
        return merge(D,L,count,S);
    }



    if(D->left!=NULL){
    if(L->pri<D->data){
   //cout<<L->pri<<" "<<D->pri<<" ";
    count++;
    return merge(D->left,L,count,S);}}

    if(D->right!=NULL)
    if(L->pri>D->data && D->right->data>L->pri)
    {
        addafter(D,L->pri,D->data);
        L=L->next;
        return merge(D,L,count,S);
    }

}


int main()
{
    int n, x, y;
	cin>>n;
	DLPTR D; 
	D=new(trnode);
    D->right=D->left=NULL;
    D->data=n; 
    
	cin>>n;
	while (n!=-1)
	{
		addend(D, n);
		cin>>n;
	}

    LPTR L;
    int k;cin>>n;
    L=new(tnode);
    L->pri=n;
    L->next=NULL;
    cin>>n;
    while(n!=-1){
    addend(L,n);
    cin>>n;
    }

    int count=0;

    merge(D,L,count,D);
    cout<<endl;

    print(D);

    cout<<endl;
    cout<<count;
    cout<<endl;
    print(L);

    return 0;
}