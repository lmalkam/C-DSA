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

void print(DSTPTR T,string str,string final[],int &n) ///max wordsss
{
	if(T!=NULL){
		if(T->eow==true){
		//	cout<<str;cout<<endl;
			if(final[n].length()<=str.length())
			{
				if(final[n].length()==str.length())
                final[++n]=str;
				if(final[n].length()<str.length())
				n=0;
				final[n]=str;
			}
		}
		for(int i=25;i>=0;i--){
		    print(T->ptr[i],str+char(i+97),final,n);
		}
	}
}

int print(DSTPTR T) //count
{   static int count=0;
	if(T!=NULL){
		if(T->eow==true){
			count++;
		}
		for(int i=25;i>0;i--){
		    print(T->ptr[i]);
		}
		return count;
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
int main()
{
	DSTPTR T=NULL;
	T=new(dstnode);
	for(int j=0;j<26;j++){
		T->ptr[j]=NULL;
	}
	T->eow=false;string s;
	string str;int i=0;
	cin>>str;
	while(str!="#"){
		construct(T,str,i);
		i=0;
		cin>>str;
	}
	cout<<print(T)<<endl;

	s="";
	print(T,s);cout<<endl;
	string final[100]={""};
	s="";
	i=0;
	print(T,s,final,i);
    for(int z=i;z>=0;z--)
	cout<<final[z]<<endl;
	return 0;
}