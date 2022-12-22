#include<iostream>
using namespace std;

struct trnode
{
    trnode* nextsib;
    int data;
    trnode *fc;
    int x,y;
};

typedef trnode* TPTR;

struct stack
{
    int top;
    TPTR sta[100];
};

void push(stack &s,TPTR x){
    s.sta[++s.top]=x;
    return;
}

TPTR pop(stack &s){
    return s.sta[s.top--];
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
    int a[]={1,2,3,4,5,6,7,0,0,0,8,9,0,0,0,0,10,11,12,0,0,0,14,15,16,0,0,0,0,17,18,0,0,0,0,0};
    static int i=0;
    int c=a[i++];
	if(c==0){
		return;
    }
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

void path(TPTR T,int a[],int i,int s,int t,int ind1){

    if((T->fc==NULL && T->nextsib==NULL) || T->data==t){
    if(T->data==t){
        a[i++]=T->data;
        for(int z=ind1;z<i;z++)
        cout<<a[z]<<" ";
    }
        return;
    }

    a[i]=T->data;
    if(T->data==s)
    ind1=i;
    i++;
    if(T->fc!=NULL)
    path(T->fc,a,i,s,t,ind1);
    if(T->nextsib!=NULL)
    path(T->nextsib,a,i,s,t,ind1);
}


int main(){
      
    TPTR S=NULL;

    make(S);

   // preorder(S);

    TPTR X=NULL;

    int i=-1,j=-1;

  // preorder(S);

  int s,t;
  cin>>s>>t;
  int a[100];

  path(S,a,0,s,t,0);
  cout<<endl;
  cin>>s>>t;
  path(S,a,0,s,t,0);


     return 0;
}
