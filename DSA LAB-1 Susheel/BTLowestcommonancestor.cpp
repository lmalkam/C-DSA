#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
    trnode *rightchild;
    int x;
    int y;
};

typedef trnode* BSTPTR;

struct stack
{
    int top;
    BSTPTR sta[100];
};

void push(stack &s,BSTPTR x){
    s.sta[++s.top]=x;
    return;
}

BSTPTR pop(stack &s){
    return s.sta[s.top--];
}


void make(BSTPTR &T)
{
	char c; cin>>c;
	if(c=='#')
		return;
	T=new(trnode);
	T->data=c;
    T->leftchild=NULL;
    T->rightchild=NULL;
	make(T->leftchild);
	make(T->rightchild);
}

bool path(BSTPTR T,stack &s,char ch)
{
    
    if(T==NULL)
    return false;
    push(s,T);

    if(T->data==ch)
    return true;

    if(path(T->leftchild,s,ch) || path(T->rightchild,s,ch))
    return true;

    pop(s);
    return false;
}



void LCA(BSTPTR T,char c1,char c2)
{
    stack s1,s2;
    s1.top=-1;s2.top=-1;

    bool flag1=path(T,s1,c1);
    bool flag2=path(T,s2,c2);
    BSTPTR t1,t2;

    if(flag1==false && flag2==false){
    cout<<"not found";
    return;
    }

    while(s1.top!=-1 || s2.top!=-1)
    {
        t1=pop(s1);
        t2=pop(s2);
        if(t1->data==t2->data)
        break;
    }
    while(s1.top!=-1)
    cout<<pop(s1)->data<<" ";
    cout<<t1->data;
}
int main(){
      
    BSTPTR S=NULL;

    make(S);

    char ch1,ch2;
    cin>>ch1>>ch2;

    LCA(S,ch1,ch2);
     return 0;
}
/*
ABD#HLQ###M##E##CFIN####GJP#RS##T#UV#X#YZ####K###
*/
     