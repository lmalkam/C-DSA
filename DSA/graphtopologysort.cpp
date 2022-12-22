#include<iostream>
using namespace std;

int G[5][5]={0},V[5]={0},deg[5][5]={0};

void topo(int z,int a[],int indeg[],int n)
{
    if(z==n)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
        return;
    }

    
    for(int i=0;i<5;i++)
    {
        if(indeg[i]==0)
        {
            a[n]=i;
            indeg[i]=-1;
            for(int x=0;x<5;x++)
            {
                if(G[i][x]==1)
                {
                    indeg[x]-=1;
                }
            }
            topo(z,a,indeg,n+1);
            indeg[i]=0;
            for(int x=0;x<5;x++)
            {
                if(G[i][x]==1)
                {
                    indeg[x]+=1;
                }
            }
        }
    }
}

int main(){
    int x,y;int indeg[5]={0};
     
    for(int i=0;i<4;i++)
    {
        cin>>x>>y;
        indeg[y]++;
        G[x][y]=1; 
    }

    int a[100];
    int n=0;

    topo(5,a,indeg,n);

     return 0;
}