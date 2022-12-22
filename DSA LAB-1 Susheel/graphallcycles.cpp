#include<iostream>
using namespace std;

int deg[5][5]={0},ind[5]={0};int indeg[5]={0};int n1;int a1[10];

int G[8][8] = {{0,0, 0, 0, 0, 0, 0, 0},
               {0,0, 2, 0, 1, 0, 0, 0}, 
               {0,0, 0, 0, 3,10, 0, 0}, 
               {0,4, 0, 0, 0, 0, 5, 0}, 
               {0,0, 0, 2, 0, 4, 8, 4}, 
               {0,0, 0, 0, 0, 0, 0, 6}, 
               {0,0, 0, 0, 0, 0, 0, 0}, 
               {0,0, 0, 0, 0, 0, 2, 0}, 
            };

void topo(int i,int x,int path[],int n)
{

    if(x==i){
    for(int j=0;j<n;j++)
        {
            cout<<path[j]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {
    for(int j=0;j<5;j++)
    {
        if(G[x][j]==1)
        {
            path[n]=j;
            topo(i,j,path,n+1);
        }
    }
    }
}

int main(){
    int a,b;
    

    int V[5]={0};

    int n=0;int path[10];
    path[n]=0;int z;

    n=n+1;

    int ans[10];

    for(int i=0;i<5;i++)
    {
        if(G[0][i]==1)
        {
            path[n]=i;
            topo(0,i,path,n+1);
        }
    }


     return 0;
}