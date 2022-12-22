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
    string s="ABF.G..C.DHK.L..I.J..E...";
    static int i=0;
    char c=s[i];
	if(c=='.'){
        i++;
		return;
    }
	T=new(trnode);
	T->data=c;
    T->fc=NULL;
    T->nextsib=NULL;
    i++;
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
    if(T->nextsib!=NULL)
    assignxy(T->nextsib,innumb,lev+1);
    }
}

void assignxy2(TPTR T,int innumb,int lev)
{
    if(T!=NULL){
   // cout<<innumb<<lev;
    T->x=innumb;
    T->y=lev;
    if(T->fc!=NULL);
    assignxy2(T->fc,innumb-1,lev+1);
    if(T->nextsib!=NULL)
    assignxy2(T->nextsib,innumb+1,lev);
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


void printer(TPTR T)
{
    if(T!=NULL)
    {
        for(int i=0;i<=T->y;i++)
        cout<<"***";
        cout<<T->data<<endl;
        printer(T->fc);
        printer(T->nextsib);
    }
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

    int i=-1,j=-1;

    assignxy2(S,i,j);

    printer(S);
  // preorder(S);


     return 0;
}
