#include<iostream>
using namespace std;

struct trnode
{
    trnode* zero;
    string str;
    trnode *one;
    int x,y;
};

typedef trnode* TPTR;


void insert(TPTR &T,string k,int i=0){

    if(T==NULL)
    {
        T=new(trnode);
        T->str=k;
        T->one=NULL;
        T->zero=NULL;
    }
    else{
        if(k[i]=='0')
        {
            insert(T->zero,k,i+1);
        }
        else{
            insert(T->one,k,i+1);
        }
    }
}


void inorder(TPTR T)
{
    if(T!=NULL)
    {
        inorder(T->zero);
        cout<<T->str<<endl;
        inorder(T->one);
    }
}

int main(){
      
    TPTR S=NULL;

    string s;
    cin>>s;
    while (s[0]!='#')
    {
        insert(S,s);
        cin>>s;
    }
    

    inorder(S);


     return 0;
}
