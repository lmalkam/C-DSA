#include<iostream>
using namespace std;

int deg[5][5]={0},vis[5]={0};int indeg[5]={0};int n1;int a1[10];

int G[6][6]={{0,1,1,0,0,0},
				 {0,0,1,1,0,0},
			   	 {0,0,0,1,0,0},
				 {0,0,0,0,1,0},
				 {1,1,0,0,0,1},
	             {0,0,0,0,0,0},};

struct stack
{
    int top;
    int sta[100];
};

void push(stack &s,int x){
    s.sta[++s.top]=x;
    return;
}

int pop(stack &s){
    return s.sta[s.top--];
}

void DFS(stack s)
{
    push(s,0);
    vis[0]=1;
    while(s.top!=-1)
    {
        int t=pop(s);
        if(vis[t]!=2)
        {
        cout<<t<<" ";
        vis[t]=2;
        }

        for(int i=5;i>=0;i--)
        {
            if(G[t][i]==1)
            {
                if(vis[i]!=2)
                {
                push(s,i);
                vis[i]=1;
                }

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

    stack s;
    s.top=-1;

    DFS(s);

     return 0;
}