#include<iostream>
using namespace std;

int G[10][10]={    {0,2,8,5,0},
				   {0,0,1,0,0},
				   {0,0,0,0,3},
				   {0,0,0,0,4},
				   {0,0,0,0,0}};

struct info{
	int dist=9999;
	int prev=-1;
	bool vis=false;
	int vcost;
};
void dijkstra(info a[],int start,int end){


	if(a[end].vis==true){
		cout<<a[end].dist<<endl;
		return;
	}


	info min;
	if(a[start].vis==false){
		for(int i=0;i<5;i++){
			if(G[start][i]!=0){
				a[i].dist=G[start][i];
				a[i].prev=start;
			}
		}
		a[start].vis=true;
	}

    min.dist=9999;
	for(int i=0;i<5;i++){
		if(a[i].dist<min.dist and a[i].vis==false){
			min.dist=a[i].dist;
			min.prev=i;
		}
	}

	int j=min.prev;
	for(int i=0;i<5;i++){
		if(G[j][i]!=0&&a[i].vis==false){
			if(G[j][i]+a[j].dist<a[i].dist){
				a[i].dist=G[j][i]+a[j].dist;
				a[i].prev=j;
			}
		}
	}
	
	a[j].vis=true;
	dijkstra(a,start,end);
}
int main(){
	info a[5];
	for(int i=0;i<5;i++)
	{
		a[i].vcost=i;
	}
	dijkstra(a,0,4);
	return 0;
}