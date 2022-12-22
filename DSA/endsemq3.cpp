#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
};

typedef trnode* BSTPTR;

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==-1)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}

bool check(int a[],int n)
{
    for(int i=2;i<n;i++)
    {
        if(a[i]!=a[i-1]+a[i-2])
        return 0;
    }
    return 1;
}
void path(BSTPTR T,int a[],int i,int &c){

    if(T->rightchild==NULL && T->leftchild==NULL)
    {   a[i++]=T->data;
        if(check(a,i)){
        for(int z=0;z<i;z++)
        cout<<a[z]<<" ";
        cout<<endl;
        c++;
        }
        return;
    }

    a[i]=T->data;
    if(T->leftchild!=NULL)
    path(T->leftchild,a,i+1,c);
    if(T->rightchild!=NULL)
    path(T->rightchild,a,i+1,c);
}


int main(){
      
    BSTPTR S=NULL;
    make(S);

    int a[100];
    int c=0;

    path(S,a,0,c);
    cout<<c;

    
    


     return 0;
}

