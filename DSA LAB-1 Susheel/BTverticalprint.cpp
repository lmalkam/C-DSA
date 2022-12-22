#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
    int x;
    int y;
};

typedef trnode* BSTPTR;

void insert(BSTPTR &T,int &k){

    if(T==NULL)
    {
        T=new(trnode);
        T->data=k;
        T->leftchild=NULL;
        T->rightchild=NULL;
    }
    else{
        if(k>T->data)
        {
            insert(T->rightchild,k);
        }
        else if(k<T->data){
            insert(T->leftchild,k);
        }
    }
}

void preorder(BSTPTR T){
    if(T==NULL){
        return;
    }
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    
}

void inorder(BSTPTR T){
    if(T==NULL)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        cout<<T->data<<" ";
        if(T->rightchild!=NULL)
        inorder(T->rightchild);
    
}

void make(BSTPTR &T)
{
	int c; cin>>c;
	if(c==0)
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}



void leftview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->leftchild!=NULL)
    leftview(T->leftchild,cl+1,lpl);
    if(T->rightchild!=NULL)
    leftview(T->rightchild,cl+1,lpl);
}

void rightview(BSTPTR T,int cl,int &lpl)
{
    
    if(cl>lpl)
    {
        cout<<T->data<<" ";
        lpl=cl;
    }
    if(T->rightchild!=NULL)
    rightview(T->rightchild,cl+1,lpl);
    if(T->leftchild!=NULL)
    rightview(T->leftchild,cl+1,lpl);
}

void assignxy(BSTPTR T,int &innumb,int lev)
{
    if(T!=NULL){
    if(T->leftchild!=NULL);
    assignxy(T->leftchild,innumb,lev+1);
   // cout<<innumb<<lev;
    T->x=++innumb;
    T->y=lev;
    if(T->rightchild!=NULL)
    assignxy(T->rightchild,innumb,lev+1);
    }

}

void assignxy2(BSTPTR T,int innumb,int lev)
{
    if(T!=NULL){
   // cout<<innumb<<lev;
    T->x=innumb;
    T->y=lev;
    if(T->leftchild!=NULL);
    assignxy2(T->leftchild,innumb-1,lev+1);
    if(T->rightchild!=NULL)
    assignxy2(T->rightchild,innumb+1,lev+1);
    }

}

void getmaxminy(BSTPTR T,int &max,int &min)
{
    if(T!=NULL)
    {
        if(T->x>max)
        max=T->x;
        if(T->x<min)
        min=T->x;
        getmaxminy(T->leftchild,max,min);
        getmaxminy(T->rightchild,max,min);
    }
}

void getmaxminy(BSTPTR T,int &max,int &min)
{
    if(T!=NULL)
    {
        if(T->y>max)
        max=T->y;
        if(T->y<min)
        min=T->y;
        getmaxminy(T->leftchild,max,min);
        getmaxminy(T->rightchild,max,min);
    }
}

void topview(BSTPTR T,int minx,int maxx,int i,int &sum,BSTPTR a[],int &n)
{
    if(T!=NULL)
    {
        if(i==T->x){
            //cout<<T->data<<" ";
            a[n++]=T;
            sum+=T->data;
        }
        topview(T->leftchild,minx,maxx,i,sum,a,n);
        topview(T->rightchild,minx,maxx,i,sum,a,n);
    }
}

void sort(BSTPTR a[],int n){
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]->y>a[j]->y){
            BSTPTR T=a[i];
            a[i]=a[j];
            a[j]=T;
            }
        }
    }
}

void vertical(BSTPTR T,int min,int max,int i)
{
    if(i==max+1)
    return;
    int sum=0;BSTPTR a[100];int n=0;
    static char data;int y=999;
    topview(T,min,max,i,sum,a,n);
    sort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]->data<<" ";
    cout<<sum;
    cout<<endl;
    return vertical(T,min,max,i+1);
}

int main(){
      
    BSTPTR S=NULL;

    make(S);

    int i=0,j=0;

    assignxy2(S,i,j);

    int maxx=-999,minx=999;
    getmaxminy(S,maxx,minx); 
    i=0;
    vertical(S,minx,maxx,minx);
     return 0;
}
/*
5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0
*/
     