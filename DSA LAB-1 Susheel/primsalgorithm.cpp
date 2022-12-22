#include<iostream>

using namespace std;
int G[7][7]={{0,2,4,1,0,0,0},
			 {2,0,0,2,10,0,0},
			 {4,0,0,2,0,5,0},
			 {1,3,2,0,7,8,4},
			 {0,10,0,7,0,0,6},
			 {0,0,5,8,0,0,1},
			 {0,0,0,4,6,1,0}};


void prims(int &count,int visited[],int n)
{
	if(n==7)
	return;
	int min=1000,min_l,min_r;
	for(int i=0;i<7;i++){
		if(visited[i]==1){
			int l=i;
			for(int j=0;j<7;j++){
				if(G[l][j]!=0 && G[l][j]<min && visited[j]==0){
					min=G[l][j];
					min_l=l,min_r=j;
				}
			}
		}
	}
	count+=min;
	G[min_l][min_r]=1000;
	G[min_r][min_l]=0;
	visited[min_r]=1;
	n++;
	prims(count,visited,n);
}

int main()
{
	int count=0;
	int visited[7]={0};
	int n=0;
	visited[0]=1;
	n++;
	prims(count,visited,n);
	for(int i=0;i<7;i++)
	{
		for(int j=6;j>=0;j--)
		{
			if(G[i][j]==1000)
			cout<<i+1<<" "<<j+1<<endl;
		}
	}
	cout<<count<<" ";
	return 0;
}