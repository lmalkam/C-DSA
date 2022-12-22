#include<iostream>
using namespace std;
struct trnode
{
	trnode* lc;
	int data;
	trnode* rc;
};
typedef trnode* bstptr;
void insert(bstptr &T,int n)
{
	if(T==NULL){
		T=new(trnode);
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
void cbt(bstptr &T)
{
	int n;
	cin>>n;
	if(n==0) return;
	
	T=new(trnode);
	T->data=n;
	T->lc=T->rc=NULL;
	cbt(T->lc);
	cbt(T->rc);
}
void fillarray(bstptr &T, int A[],int &i)
{
	if(T!=NULL){
		A[i]=T->data;i++;
		fillarray(T->lc,A,i);
		fillarray(T->rc,A,i);
	}
}
void inorder(bstptr T)
{    
	if(T!=NULL){
		inorder(T->lc);
		cout<<T->data<<" ";
		inorder(T->rc);
	}
}
void sort(int A[], int i)
{
    for(int j=0;j<i;j++){
        for(int k=j+1;k<i;k++){
            if(A[j]>A[k]){
                int temp=A[k];
                A[k]=A[j];
                A[j]=temp;
            }
        }
    }
}
void fillin(bstptr &T,int A[],int &l)
{
    if(T!=NULL){
        fillin(T->lc,A,l);
        T->data=A[l];l++;
        fillin(T->rc,A,l);
    }
}
int main()
{
	bstptr T1=NULL;
	cbt(T1);
	//inorder(T1);cout<<endl;
	int A[100],i=0,l=0;
	fillarray(T1,A,i);
	sort(A,i);
	fillin(T1,A,l);
	inorder(T1);cout<<endl;
	/*for(int j=0;j<i;j++){
		cout<<A[j]<<" ";
	}*/
	return 0;
}