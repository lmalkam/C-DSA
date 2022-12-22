#include<iostream>
#include<cstring>
using namespace std;
struct dstnode
{
	dstnode* ptr[26];
	bool eow;
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
			for(int j=0;j<26;j++){
				T->ptr[int(str[i]-97)]->ptr[j]=NULL;
				T->ptr[int(str[i]-97)]->eow=false;
			}
			construct(T->ptr[int(str[i]-97)],str,i+1);
		}
		else
		{
			construct(T->ptr[int(str[i]-97)],str,i+1);
		}
	}
}
void print(DSTPTR T,string str)
{
	if(T!=NULL){
		if(T->eow==true){
			cout<<str;cout<<endl;
		}
		for(int i=25;i>0;i--){
		    print(T->ptr[i],str+char(i+97));
		}
	}
}
int main()
{
	DSTPTR T=NULL;
	T=new(dstnode);
	for(int j=0;j<26;j++){
		T->ptr[j]=NULL;
	}
	T->eow=false;
	string str;int i=0;
	cin>>str;
	while(str!="#"){
		construct(T,str,i);
		i=0;
		cin>>str;
	}
	
	print(T,"");
	return 0;
}
