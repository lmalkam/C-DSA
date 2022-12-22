#include<iostream>
using namespace std;

struct stack
{
	int f;
	int r;
	int size;
	int element[100];
};
void enque(stack &q,int x)
{
	if((q.r+1)%q.size==q.f)
	return ;
	else
	{
		if(q.r==-1)
		{
			q.f=0;
			q.r=0;
		}
		else
		{
			q.r=(q.r+1)%q.size;
		}
		q.element[q.r]=x;
	}
}
int deque(stack &q)
{
	if(q.f==-1)
	return 0;
	else
	{
		int t=q.element[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
		{
			q.f=(q.f+1)%q.size;
		}
		return t;
	}
}

int main(){
      int m,n;
      cin>>n>>m;

      stack q;q.f=-1,q.r=-1;q.size=100;

      int a[m];

      int i=0;
      while(i<m)
      enque(q,i++);

      i=0;
      while (q.f!=-1)
      {
          for(int i=0;i<n-1;i++)
          {
              enque(q,deque(q));
          }
          a[i++]=deque(q);
      }

      for(int i=0;i<m;i++)
      cout<<a[i]<<" ";  

     return 0;
}