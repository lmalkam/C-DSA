#include<iostream>
using namespace std;

struct trnode
{
    trnode* leftchild;
    char data;
    trnode *rightchild;
    int x;
    int y;
    bool flag=true;
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
    if(T!=NULL){
        if(T->flag==true)
        cout<<T->data<<" ";
        preorder(T->leftchild);
        preorder(T->rightchild);
    }
    
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

void makefalse(BSTPTR T,int k)
{
    if(T!=NULL)
    {
        if(T->data==k)
        T->flag=false;
        makefalse(T->leftchild,k);
        makefalse(T->rightchild,k);
    }
}

void topview(BSTPTR T,int minx,int maxx,int i,char &data,int &y)
{
    if(T!=NULL)
    {
        if(i==T->x){
            if(y>=T->y){
                data=T->data;
                y=T->y;
            }
        }
        topview(T->leftchild,minx,maxx,i,data,y);
        topview(T->rightchild,minx,maxx,i,data,y);
    }
}

void topview(BSTPTR T,int min,int max,int i)
{
    if(i==max+1)
    return;
    static char data;int y=999;
    topview(T,min,max,i,data,y);
    makefalse(T,data);
    return topview(T,min,max,i+1);
}

void bottomview(BSTPTR T,int minx,int maxx,int i,char &data,int &y)
{
    if(T!=NULL)
    {
        if(i==T->x){
            if(y<=T->y){
                data=T->data;
                y=T->y;
            }
        }
        bottomview(T->leftchild,minx,maxx,i,data,y);
        bottomview(T->rightchild,minx,maxx,i,data,y);
    }
}

void bottomview(BSTPTR T,int min,int max,int i)
{
    if(i==max+1)
    return;
    static char data;int y=-999;
    bottomview(T,min,max,i,data,y);
     makefalse(T,data);
    return bottomview(T,min,max,i+1);
}

bool find(BSTPTR &T,char c)
{
    if(T!=NULL)
    {
        if(T->data==c)
        return true;
        find(T->leftchild,c);
        find(T->rightchild,c);
    }
}

bool check(BSTPTR &T,char c1,char c2)
{
    bool flag1,flag2;
    if(T->leftchild!=NULL)
    flag1=find(T->leftchild,c1);
    if(T->rightchild!=NULL)
    flag2=find(T->rightchild,c2);
    if(flag2==true && flag1==true){
    cout<<T->data;
    return true;
    }
}

void common(BSTPTR &T,char c1,char c2)
{
    if(T!=NULL)
    {
        if(check(T,c1,c2)==true);
        return;
        common(T->leftchild,c1,c2);
        common(T->rightchild,c1,c2);
    }
}

int main(){
      
    BSTPTR S=NULL;

    make(S);

    int i=0,j=0;

    char c1,c2;
    cin>>c1>>c2;

    common(S,c1,c2);

   // preorder(S);
     return 0;
}
/*
ABD#HLQ###M##E##CFIN####GJP#RS##T#UV#X#YZ####K###
*/
     