#include<iostream>
#include<cstring>
using namespace std;

struct dstnode
{
	dstnode* ptr[26]={NULL};
	bool eow=false;
};

typedef dstnode* DSTPTR;

void construct(DSTPTR &T,string str,int i)
{
	if(i==str.length())
	{
		T->eow=true;
		return ;
	}
	else 
	{
		if(T->ptr[int(str[i]-97)]==NULL)
		{
			T->ptr[int(str[i]-97)]=new(dstnode);
			construct(T->ptr[int(str[i]-97)],str,i+1);
		}
		else
		{
			construct(T->ptr[int(str[i]-97)],str,i+1);
		}
	}
}


void print(DSTPTR T,string str)  //printing
{
	if(T!=NULL){
		if(T->eow==true){
			cout<<str<<" ";
		}
		for(int i=25;i>0;i--){
		    print(T->ptr[i],str+char(i+97));
		}
	}
}

void checker(DSTPTR T,string target,string s,int j)
{
    if(j>=target.length()-1){
    if(T->eow==true)
    cout<<s<<" ";
    for(int i=0;i<26;i++){
    if(T->ptr[i]!=NULL)
	checker(T->ptr[i],target,s+char(i+97),j+1);
	}
    }
    if(T->ptr[int(target[j])-97]!=NULL)
	checker(T->ptr[int(target[j])-97],target,s+char(int(target[j])),j+1);
}

int main()
{
	DSTPTR T=NULL;
	T=new(dstnode);
	T->eow=false;
    string s="";
	string str;int i=0;
	cin>>str;
	while(str!="#"){
		construct(T,str,i);
		i=0;
		cin>>str;
	}
    string target;cin>>target;
    while(target!="#"){
    checker(T,target,s,0); 
    cin>>target;
    }

	return 0;
}