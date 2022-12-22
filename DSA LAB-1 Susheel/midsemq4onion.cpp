#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char pri;
    trnode *rightchild;
    int x;
    int y;
};

typedef trnode* BSTPTR;

struct stack
{
	int f,r,s;
	BSTPTR E1[20];
};
void equeue(stack &Q ,BSTPTR x)
{
	if((Q.r+1)%Q.s==Q.f){
		cout<<"full...";
	}
	else{
		if(Q.r==-1){
			Q.r=0;
			Q.f=0;
		}
		else 
		Q.r=(Q.r+1)%Q.s;
		
		Q.E1[Q.r]=x;
	}
}
BSTPTR dqueue(stack &Q)
{
	BSTPTR t;
	if(Q.f==-1) cout<<"empty queue...";
	else{
		t=Q.E1[Q.f];
		if(Q.f==Q.r){
			Q.f=-1,Q.r=-1;
		}
		else
		Q.f=(Q.f+1)%Q.s;
		return t;
	}
}


void preorder(BSTPTR T){
    if(T==NULL){
        return;
    }
        cout<<T->pri<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    
}

void inorder(BSTPTR T){
    if(T==NULL)
    return;
        if(T->leftchild!=NULL)
        inorder(T->leftchild);
        cout<<T->pri<<" ";
        if(T->rightchild!=NULL)
        inorder(T->rightchild);
    
}

void make(BSTPTR &T)
{
	char c; cin>>c;
	if(c=='#')
		return;
	T=new(trnode);
	T->pri=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}

void levelorder(BSTPTR T,stack Q,BSTPTR k,char a[][10],int b[],int &i)
{
    equeue(Q,T);
    equeue(Q,k);
    while(Q.f!=-1){
        BSTPTR temp=dqueue(Q);
        if(temp==NULL){
            if(Q.f==-1){
                cout<<"dash";
                return;
            }
            else{
                i++;
                equeue(Q,k);
                continue;
            }
        }
        else {
        a[i][b[i]++]=temp->pri;}

        if(temp->leftchild!=NULL){
            equeue(Q,temp->leftchild);
        }
        if(temp->rightchild!=NULL){
            equeue(Q,temp->rightchild);
        }
    }
}



int main(){
      
    BSTPTR S=NULL;

    make(S);
    //preorder(S);

    char a[10][10];
    int b[10]={0,0,0,0,0,0,0,0,0,0};
    BSTPTR X=NULL;
    stack q;q.f=-1;q.r=-1;q.s=100;

    int i=0;
    levelorder(S,q,X,a,b,i);
    cout<<i;
    int n=i;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i];j++)
        {
            cout<<a[i][j]<<" ";
        }
    }

    return 0;
}
/*
5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0
*/
     