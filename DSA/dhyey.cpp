#include<iostream>
using namespace std;
void equalrows(int a[10][10],int m,int n,int count,int i,int k,int j)
{
	if(i==m)
	return;
	
		if(j==n)
		{
			if(count==n)
			{
				cout<<i<<" ";
				equalrows(a,m,n,0,++i,0,0);
			}
			else if(k!=m)
			equalrows(a,m,n,0,i,++k,0);
			else
			equalrows(a,m,n,0,++i,0,0);	
		}

		if(a[k][j]==a[i][j] && k!=i)
		count+=1;
		 return equalrows(a,m,n,count,i,k,++j);
	

}
void equalcols(int a[10][10],int m,int n,int count,int i,int k,int j)
{
	if(i==n)
	return;
		if(k==m)
		{
			if(count==m)
			{
				cout<<i<<" ";
				equalcols(a,m,n,0,++i,0,0);
			}
			else if(j!=n)
			equalrows(a,m,n,0,i,0,++j);
			else
			equalrows(a,m,n,0,++i,0,0);
		}
		if(a[i][k]==a[j][k] && j!=i)
		count+=1;
		equalcols(a,m,n,count,i,++k,j);
	
	

}
int main()
{
	int m,n;
	cin>>m>>n;
	int a[10][10];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		cin>>a[i][j];
		}
	}
	
	equalrows(a,m,n,0,0,0,0);
	cout<<endl;
	equalcols(a,m,n,0,0,0,0);
}