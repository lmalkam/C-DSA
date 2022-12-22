#include<iostream>
using namespace std;

int deg[5][5]={0},vis[5]={0};int indeg[5]={0};int n1;int a1[10];

int G[9][9]={{0,1,0,1,1,0,0,0,0},
				 {0,0,1,0,1,0,0,0,0},
				 {0,0,0,0,0,1,0,0,0},
				 {0,0,0,0,1,0,1,0,0},
				 {0,0,0,0,0,1,0,1,0},
	             {0,0,0,0,0,0,0,0,0},
	             {0,0,0,0,1,0,0,1,0},
	             {0,0,0,0,0,1,0,0,1},
	             {0,0,0,0,0,0,0,0,0}};

struct stack
{
    int f,r,s;
    int que[100];
};

void enqueue(stack &q,int x){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else{
        q.r=(q.r+1)%q.s;
    }
        q.que[q.r]=x;
    }
}

int dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
    else{
        int t=q.que[q.f];
        if(q.r==q.f)
        {
            q.f=-1;
            q.r=-1;
        }
        else
        q.f=(q.f+1)%q.s;
        return t;
    } 
}

void BFT(stack q)
{
    enqueue(q,0);
    vis[0]=1;
    while(q.r!=-1)
    {
        int t=dequeue(q);
        cout<<t<<" ";
        for(int i=0;i<9;i++)
        {
            if(G[t][i]==1)
            {
                if(vis[i]!=1)
                enqueue(q,i);
                vis[i]=1;
            }
        }
    }
}

int main(){
    int a,b;
    

    int V[5]={0};

    int n=0;int path[10];
    path[n++]=0;int z;

    int ans[10];

    stack q;
    q.f=q.r=-1;q.s=100;

    BFT(q);


     return 0;
}