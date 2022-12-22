#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    int data;
    trnode *rightchild;
    int x;
    int y;
    bool flag=true;
};

typedef trnode* BSTPTR;

void make(BSTPTR &T,int H[],int i,int n)
{
	T=new(trnode);
	T->data=H[i];
    T->leftchild=NULL;
    T->rightchild=NULL;
    if(2*i+1<=n)
	make(T->leftchild,H,2*i+1,n);
    if(2*i+2<n)
	make(T->rightchild,H,2*i+2,n);
}

void preorder(BSTPTR T){
    if(T!=NULL){
         cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
}
int checkheap(int H[],int n,int i)
{
	if(i<n){
		if(2*i+1<n && 2*i+2<n){
			if(H[i]<H[2*i+1] && H[i]<H[2*i+2]){
				i+=1;
				checkheap(H,n,i);
			}
			else return 0;
		}
	}
	return 1;
}

void heapyup(int H[],int i)
{
    if(i==0)
    return;
    int p=(i-1)/2;
    if(H[p]>H[i])
    {
        swap(H[p],H[i]);
        i=p;
        return heapyup(H,i);
    }
    else
    return;
}

void createheap(int H[],int size,int &n)
{
    if(n<size)
    {
        int k;cin>>k;
        if(k==-1)
        return;
        H[n]=k;
        heapyup(H,n);
        n++;
        createheap(H,size,n);
    }
}

void heapydown(int H[],int i,int n)
{
		int mini,li,ri;
		li=2*i+1;ri=2*i+2;
		mini=i;
		if(H[mini]>H[li] && li<=n) mini=li;
		if(H[mini]>H[ri] && ri<=n) mini=ri;
		swap(H[i],H[mini]);
		if(i!=mini)
		heapydown(H,mini,n);
}

void heapsort(int H[],int n)
{
	if(n==0){
		cout<<H[0];
		return;
	}
	else{
		cout<<H[0]<<" ";
		H[0]=H[n];
		n=n-1;
        heapydown(H,0,n);
		heapsort(H,n);
	}
}


void merge(BSTPTR &T1,BSTPTR T2,int H1[],int H2[],int n1,int n2)
{
    static int i=n1;
    if(i==n1+n2){
    make(T1,H1,0,n1+n2-1);
    return;}
    if(T2!=NULL)
    {
        H1[i]=T2->data;
        heapyup(H1,i);
        i++;
        merge(T1,T2->leftchild,H1,H2,n1,n2);
        merge(T1,T2->rightchild,H2,H2,n1,n2);
    }

}

int main(){

      int H1[1000],H2[1000];
      int size=100;
      int n1=0,n2=0;

      createheap(H1,size,n1);



      return 0;
}