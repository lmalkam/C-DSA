#include<iostream>
using namespace std;

string createST(string ST[], string A, int l, int r, int i=0)
{
	if(l==r)
	{
		ST[i]=A[l];
		return ST[i];
	}
	
	int mid=(l+r)/2;
	ST[i]= createST(ST, A, l, mid, 2*i+1) + createST(ST, A, mid+1, r, 2*i+2);
	return ST[i];	
}

string update(string ST[], int l, int r, int pos, char c, int i=0)
{
    if(pos<l || r<pos)
       return ST[i];
       
	if(l==r)
	{
		ST[i]=c;
		return ST[i];
	}
	
	if(l<=pos && pos<=r) ////////////
	{
		int mid=(l+r)/2;
		string x=update(ST, l, mid, pos, c, 2*i+1), y=update(ST, mid+1, r, pos, c, 2*i+2);
		
		ST[i]=x+y;
	}
	return ST[i];
}
////////////////////////////////////
int distinct(string s)
{
	int a[26]={0}, c=1;
	for(int i=0; i<s.size(); i++)
		a[s[i]-97]+=1;
		
	for(int i=0; i<26; i++)
	{
		if(a[i]==1)
			c++;
	}
	return c;
}

string rstring(string ST[], int l, int r, int a, int b, int i=0)
{
	if(a<=l && r<=b)
	    return ST[i];	    
	    
	if(a>r || b<l)
	    return "";
	    
	int mid=(l+r)/2;
	return rstring(ST, l, mid, a, b, 2*i+1) + rstring(ST, mid+1, r, a, b, 2*i+2);	
}

int main()
{
	string ST[50], A=""; int n=0, a, b, c, q; char ch;
	
	do //dfcbbcfeeedbaea# 17  1 6 e  1 4 b   2 6 14
	{
		cin>>ch;
		if(ch!='#')
		{
		    A+=ch;
		    n++;
		}
	}while(ch!='#');
	n-=2;
	createST(ST, A, 0, n);
	
	cin>>q; //17
//1 6 e  1 4 b  2 6 14  1 7 b  1 12 c   2 6 8  2 1 6  1 7 c  1 2 f  1 10 a  2 7 9  1 10 a  1 14 b  1 1 f  2 1 11  1 14 e  2 14 15
	for(int i=0; i<q; i++)
	{
		cin>>a;
		switch(a)
		{
			case(1):
				cin>>b>>ch;
				update(ST, 0, n, b, ch);
				break;
			case(2):
				cin>>b>>c;
				cout<<distinct(rstring(ST, 0, n, b, c))<<" ";
				break;
		}
	}

	return 0;
}