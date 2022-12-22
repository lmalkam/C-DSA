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

struct stack
{
    int f,r,s;
    BSTPTR que[100];
};

void enqueue(stack &q,BSTPTR x){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else{
        q.r=(q.r+1)%q.s;
    }
        q.que[q.r]=x;
    }
}

BSTPTR dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
    else{
        BSTPTR t=q.que[q.f];
        if(q.r==q.f)
        {
            q.f=-1;
            q.r=-1;
        }
        else
        q.f=(q.f+1)%q.s;
        return t;
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




void assignxy(BSTPTR T,int &innumb,int lev)
{
    if(T!=NULL){
    if(T->leftchild!=NULL);
    assignxy(T->leftchild,innumb,lev+1);
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
        if(T->y>max)
        max=T->y;
        if(T->y<min)
        min=T->y;
        getmaxminy(T->leftchild,max,min);
        getmaxminy(T->rightchild,max,min);
    }
}

void search(BSTPTR &C,BSTPTR &P,int x)
{
    while(C->data!=x && C!=NULL)
    {
        P=C;
        if(x<C->data)
        C=C->leftchild;
        else
        C=C->rightchild;
    }
}

void deletenode(BSTPTR T,int x)
{
    BSTPTR P=NULL,C=T;
         search(C,P,x);

     if(C->leftchild==NULL && C->rightchild==NULL){    
         if(P->rightchild==C){
         P->rightchild=NULL;
         }
         else{
         P->leftchild=NULL;
         }
         return;
    }
}

BSTPTR levelreturn(BSTPTR T1,BSTPTR &T2,stack &q)
{
    BSTPTR temp=dequeue(q);

    if(temp->rightchild==NULL && temp->leftchild==NULL)
    {
        deletenode(T2,temp->data);
        return temp;
    }

    if(temp->leftchild!=NULL)
    enqueue(q,temp->leftchild);
    if(temp->rightchild!=NULL)
    enqueue(q,temp->rightchild);

    if(q.f==-1)
    return NULL;
    
    levelreturn(T1,T2,q);
    
}

void makecomp(BSTPTR T1,BSTPTR T2,stack &q1,int level,BSTPTR S)
{
    if(T1!=NULL)
    {
        if(T1->y<=level)
        {
            if(T1->leftchild==NULL && T1->rightchild!=NULL)
           {
            BSTPTR X=levelreturn(S,T2,q1);
            q1.f=q1.r=-1;
            enqueue(q1,S);
            T1->leftchild=X;
           }
           if(T1->leftchild!=NULL && T1->rightchild==NULL)
           {
            BSTPTR X=levelreturn(S,T2,q1);
            q1.f=q1.r=-1;
            enqueue(q1,S);
            T1->rightchild=X;
           }
        }
        makecomp(T1->leftchild,T2,q1,level,S);
        makecomp(T1->rightchild,T2,q1,level,S);
    }
}


int main(){
      
    BSTPTR T1=NULL,T2=NULL;

    make(T1);
    make(T2);

    int i=0,j=0;

    assignxy2(T1,i,j);
    int maxy=-999;int miny=999;
    getmaxminy(T1,maxy,miny); 
    i=0;

    int level=maxy-1;
    stack q;
    q.f=-1;q.r=-1;q.s=100;
    enqueue(q,T2);

    //levelreturn(T1,T2,q);

    makecomp(T1,T2,q,level,T1);

    preorder(T1);
    return 0;
}
/*
ABD#HLQ###M##E##CFIN####GJP#RS##T#UV#X#YZ####K###
*/
     