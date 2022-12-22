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
    cout<<data<<" ";
    return topview(T,min,max,i+1);
}

void bottomview(BSTPTR T,int minx,int maxx,int i,int &data,int &prev,int &y)
{
    if(T!=NULL)
    {
        if(i==T->x){
            // if(T->y==i)
            //  {
            //      cout<<"";
            //  } 
            if((y<=T->y) && (T->rightchild==NULL && T->leftchild==NULL)){
                static int prev=T->data;
                data=T->data;
                y=T->y;
                if(prev!=data)
                cout<<prev<<" ";
                prev=data;
            }
        }
        bottomview(T->leftchild,minx,maxx,i,data,prev,y);
        bottomview(T->rightchild,minx,maxx,i,data,prev,y);
    }
}

void bottomview(BSTPTR T,int min,int max,int i)
{
    static int data;
    if(i==max+1){
        cout<<data<<" ";
    return;}
    int y=-999;int prev;
    bottomview(T,min,max,i,data,prev,y);
    return bottomview(T,min,max,i+1);
}

void printright(BSTPTR T)
{
    if(T!=NULL){
    if(T->rightchild!=NULL)
    printright(T->rightchild);
    cout<<T->data<<" ";
    }
}

void printleft(BSTPTR L,int x,int y)
{
    while(x!=y || L!=NULL){
        cout<<L->data<<" ";
        ++x;++y;
        L=L->leftchild;
    }

}
void border(BSTPTR T,int maxx,int minx,int x,int y)
{

    printleft(T,x,y);

    bottomview(T,minx,maxx-1,minx+1);

    printright(T);
}

int main(){
      
    BSTPTR S=NULL;

    make(S);

    int i=0,j=0;

    assignxy2(S,i,j);
    int maxx=-999,maxy=-999,minx=999, miny=999;
    getmaxminy(S,maxx,minx); 
   // getmaxminy(S,maxy,miny);
    i=0;
    border(S,maxx,minx,0,0);
     return 0;
}
/*
5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0
*/
     