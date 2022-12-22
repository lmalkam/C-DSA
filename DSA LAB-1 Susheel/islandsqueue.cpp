#include<iostream>
using namespace std;

struct stack
{
    int f,r,s;
    int que[100];
};

void enqueue(stack &q,int a){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else
        q.r=(q.r+1)%q.s;
        q.que[q.r]=a;
    }
}

int dequeue(stack &q){
    if(q.f==-1)
    cout<<"EMPTY";
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

void back(stack &q,int a[10][10],int i,int j){

     enqueue(q,a[i][j]);
    a[i][j]=0;

    if(a[i+1][j]==1 and i+1<10)
    back(q,a,i+1,j);
    if(a[i][j+1]==1 && j+1<10)
    back(q,a,i,j+1);
    if(a[i-1][j]==1 && i-1>=0)
    back(q,a,i-1,j);
    if(a[i][j-1]==1 and j-1>=0)
    back(q,a,i,j-1);
    if(a[i+1][j+1]==1 && i+1<10 and j+1<10)
    back(q,a,i+1,j+1);
    if(a[i-1][j-1]==1 and i-1>=0 and j-1>=0)
    back(q,a,i-1,j-1);
    if(a[i+1][j-1]==1 and i+1<10 and j-1>=0)
    back(q,a,i+1,j-1);
    if(a[i-1][j+1]==1 and i-1>=0 and j+1<=10)
    back(q,a,i-1,j+1);
    dequeue(q);
    return;
}

int main(){
      

      int a[10][10]=

      {1,0,1,0,0,0,1,1,1,1,
0,0,1,0,1,0,1,0,0,0,
1,1,1,1,0,0,1,0,0,0,
1,0,0,1,0,1,0,0,0,0,
1,1,1,1,0,0,0,1,1,1,
0,1,0,1,0,0,1,1,1,1,
0,0,0,0,0,1,1,1,0,0,
0,0,0,1,0,0,1,1,1,0,
1,0,1,0,1,0,0,1,0,0,
1,1,1,1,0,0,0,1,1,1,
};
      int b[10][10]={0};

      int z=0;

      stack q;q.r=-1;q.f=-1;q.s=50;

      for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
		if(a[i][j]==1){
            z++;
            back(q,a,i,j);
        }
        }
	}

    cout<<z;
     return 0;
}