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
      
      int a[100];
      int i=0,n;
      while(i>=0){
          cin>>a[i];
          if(a[i]==-1)
          break;
          i++;
      }n=i;

      stack q;q.f=-1;q.r=-1;q.size=50;
      stack q2;q2.f=-1;q2.r=-1;q2.size=50;

      for(int i=0;i<n;i++)
      enque(q,a[i]);

      for(int i=0;i<n-2;i++){
          int a=deque(q);
          int b=deque(q);
          if(a>b)
          enque(q2,a);
          else
          enque(q2,b);
      }
      
      while(q2.f!=-1)
      cout<<deque(q2)<<" ";

     return 0;
}