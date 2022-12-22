#include<iostream>
using namespace std;

struct trnode
{
    trnode* nextsib;
    char data;
    trnode *fc;
    int x,y;
};

typedef trnode* TPTR;

struct stack
{
    int front;
    int rear;
    int size;
    TPTR elements[100];
};

void eque(stack &Q,TPTR x){
    if(Q.rear+1%Q.size==Q.front)
    cout<<"FULL";
    else{
        if(Q.rear==-1)
        {
            Q.rear=0;Q.front=0;
        }
        else{
        Q.rear=(Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear]=x;
    }
}

TPTR dequeue(stack &Q){
    if(Q.front==-1)
    cout<<"";
    else{
        TPTR t=Q.elements[Q.front];
        if(Q.rear==Q.front)
        {
            Q.front=-1;
            Q.rear=-1;
        }
        else
        Q.front=(Q.front+1)%Q.size;
        return t;
    }
}

void printl(TPTR F,TPTR T,TPTR S)
{
    if(T==NULL || S==NULL || F==NULL)
    return;

    cout<<S->data<<" ";
    printl(F,T,S->nextsib);
    printl(F,T->nextsib,T->nextsib->fc);
    printl(F->fc,F->fc,T->fc);
}


void make(TPTR &T)
{
	char c; cin>>c;
	if(c=='.')
		return;
	T=new(trnode);
	T->data=c;
    T->fc=NULL;
    T->nextsib=NULL;
	make(T->fc);
	make(T->nextsib);
}

void preorder(TPTR T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        preorder(T->fc);
        preorder(T->nextsib);
    }
}

void levelorder(TPTR T,stack &q,TPTR X)
{
    eque(q,T);
    eque(q,X);
    while(q.front!=-1){
    TPTR temp=dequeue(q);
    if(temp==NULL){
    if(q.front==-1){
        cout<<"/"<<endl;
    return;}
    else{
    cout<<"/ "<<endl;
    eque(q,X);
    continue;
    }
    }
    else
    cout<<temp->data<<" ";
    if(temp->fc!=NULL){
    eque(q,temp->fc);
    temp=temp->fc;
    while(temp->nextsib!=NULL){
    eque(q,temp->nextsib);
    temp=temp->nextsib;
    }
    }
    }
}

void assignxy(TPTR T,int &innumb,int lev)
{
    if(T!=NULL){
    if(T->fc!=NULL);
    assignxy(T->fc,innumb,lev+1);
    T->x=++innumb;
    T->y=lev;
    if(T->rightchild!=NULL)
    assignxy(T->rightchild,innumb,lev+1);
    }
}

void printchild(TPTR T,char ch)
{
    if(T!=NULL)
    {
        if(T->data==ch)
        {
            if(T->fc!=NULL)
            T=T->fc;
            else 
            return;
            while(T!=NULL)
            {
                cout<<T->data;
                T=T->nextsib;
            }
            if(T==NULL)
            return;
        }
        printchild(T->fc,ch);
        printchild(T->nextsib,ch);
    }
}

void height(TPTR T,int &max,int curr)
{
    if(T!=NULL){
    height(T->fc,max,curr+1);
    if(curr>max)
    {
        max=curr;
        curr=-1;
    }
    height(T->nextsib,max,curr);
    }
}
int hgt(TPTR T)
{
    if(T==NULL) return 0;
    else return max(hgt(T->fc),hgt(T->nextsib))+1;
}

int main(){
      
    TPTR S=NULL;

    make(S);

   // preorder(S);

    stack q;
    q.front=-1;
    q.size=100;
    q.rear=-1;

  TPTR X=NULL;

    levelorder(S,q,X);

    preorder(S);


     return 0;
}
