#include<iostream>
using namespace std;

int all_visited(int V[],int n)
{
	int flag=1;
	for(int i=0;i<n;i++)
	{
		if(V[i]==0)
		flag=0;
	}
	return flag;
}
void postordernum(int G[10][10],int V[],int n,int k,int post[],int &l)
{
//	if(all_visited(V,n))
//	return ;
//	else
//	{
		for(int i=n-1;i>=0;i--)
		{
			if(G[k][i]==1 && V[i]==0)
			{
				V[i]=1;
				postordernum(G,V,n,i,post,l);
				post[i]=l;
				l++;
			}
		}
//	}
}
int main()
{
	int n=10;
	int G[10][10]={ {0,1,0,1,0,0,0,0,0,0},
                    {0,0,1,0,0,1,0,0,0,0},
					{1,0,0,1,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0,0,0,1},
                    {0,0,0,0,0,1,0,0,0,1},
					{0,0,0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,0,0,0,1,0}};
	int V[10]={0};
	int k=1;
	V[k]=1;
	int post[10];int l=1;
	postordernum(G,V,n,k,post,l);
	post[k]=l;l=l+1;

	k=7;
	V[k]=1;
	postordernum(G,V,n,k,post,l);
	post[k]=l;l=l+1;

	k=6;
	V[k]=1;
	postordernum(G,V,n,k,post,l);
	post[k]=l;l=l+1;

	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" "<<post[i]<<endl;
	}


	return 0;
}