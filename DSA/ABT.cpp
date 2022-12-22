#include<iostream>
#include<cstring>
using namespace std;
struct dstnode
{
	dstnode* ptr[7];
	bool eow;
};

typedef dstnode* DSTPTR;

void construct(DSTPTR &T,string str,int &i)
{
	if(i==str.length())
	{
		T->eow=true;
		return ;
	}
	else 
	{
		if(T->ptr[int(str[i]-65)]==NULL)
		{
			T->ptr[int(str[i]-65)]=new(dstnode);
			for(int j=0;j<7;j++){
				T->ptr[int(str[i]-65)]->ptr[j]=NULL;
			}
			T->ptr[int(str[i]-65)]->eow=false;
			i++;
			construct(T->ptr[int(str[i-1]-65)],str,i);
		}
		else
		{
			i++;
			construct(T->ptr[int(str[i-1]-65)],str,i);
		}
	}
}
void print(DSTPTR T,string s)
{
	if(T!=NULL){
		if(T->eow==true){
			cout<<s;cout<<endl;
		}
		for(int i=0;i<7;i++){
		    print(T->ptr[i],s+char(i+65));
		}
	}
}
int main()
{
	DSTPTR T=NULL;
	T=new(dstnode);
	for(int j=0;j<7;j++){
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