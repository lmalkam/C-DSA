#include<iostream>
using namespace std;

int G[5][5]={0};
int deg[5][5]={0},ind[5]={0};int indeg[5]={0};

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
    else{
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
     
    while(a!=-1 && b!=-1)
    {
        cin>>a>>b;
      //  deg[a][b]++;
        G[a][b]=1;
      //  indeg[b]++;
    }

    int n=0;int path[10];
    path[n++]=0;

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
