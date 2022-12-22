#include<iostream>
using namespace std;

struct trnode
{
    trnode* ptr[2];
    bool eow;
};

typedef trnode* TPTR;

void insert(TPTR &T,string str,int &i){

    if(i==str.length())
    {
        T=new(trnode);
        T->ptr[0]=T->ptr[1]=NULL;
        T->eow=true;
        return;
    }

    if(T==NULL)
    {
        T=new(trnode);
        T->ptr[0]=T->ptr[1]=NULL;
        T->eow=false;
    }
    else{
        if(T->ptr[str[i]-'0']==NULL)
        {
            i++;
            insert(T->ptr[str[i]-'0'],str,i);
        }
        else if(T->ptr[str[i]-'0']==NULL){
            i++;
            insert(T->ptr[str[i]-'0'],str,i);
        }
        return;
    }
}

void inorder(TPTR T,string s)
{
    if(T==NULL)
    return;
    else
    {
        if(T->eow==true && T!=NULL)
        {
            cout<<s<<endl;
        }
            inorder(T->ptr[0],s+'0');
            inorder(T->ptr[1],s+'1');
    }
}

int main(){
      
    TPTR S=NULL;

    string s;
    cin>>s;
    int i=0;
    while (s[0]!='#')
    {
        insert(S,s,i);
        i=0;
        cin>>s;
    }
    
    s="";
    inorder(S,s);


     return 0;
}
