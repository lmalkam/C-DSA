#include<iostream>

using namespace std;
int G[7][7]={{}};

void prims(int &count,int visited[],int n)
{
	if(n==7)
	return;
	int min=1000,l,r;
	for(int i=0;i<7;i++){
		if(visited[i]==1){
			int l=i;
			for(int j=0;j<7;j++){
				if(G[l][j]!=0 && G[l][j]<min && visited[j]==0){
					min=G[l][j];
					l=l,r=j;
				}
			}
		}
	}
	count+=min;
    cout<<count<<" ";
	G[l][r]=0;
	G[r][l]=0;
	visited[r]=1;
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
	cout<<count<<" ";
	return 0;
}