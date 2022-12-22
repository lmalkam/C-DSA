#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int num[100]={-2};
	int n=0;
	cin>>num[n];
	while(num[n-1]!=-1 || num[n]!=-1)
	{
		n++;
		cin>>num[n];
	}

	 for(int i=0;i<n;i++)
    cout<<num[i]<<" ";
    cout<<endl;

	int x=0;
	int newnum[100]={0};
	for(int i=1;i<n-1;i=i+2)
	{
		if(num[i]>=num[i+1])
		{
			if(num[i]>num[i+2])
			{
				num[i+2]=num[i];
				num[i+1]=num[i-1];
			}
			else
			{
				num[i+1]=num[i-1];
			}
			if(i==n-2)
			{
				newnum[x]=num[i-1];
				x++;
				newnum[x]=num[i];
				x++;
			}
		}
		else
		{
			newnum[x]=num[i-1];
			x++;
			newnum[x]=num[i];
			x++;
		}
	}
	for(int i=0;i<x;i++)
	{
		cout<<newnum[i]<<" ";
	}
	return 0;
}