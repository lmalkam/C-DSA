#include<iostream>
using namespace std;
struct stack
{
	int element[100];
	int f;
	int r;
	int size;
};
void enqueue(stack &q,int x)
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
int dequeue(stack &q)
{
	if(q.f==-1){
	return 0;
	}
	else
	{
		int t=q.element[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
		q.f=(q.f+1)%q.size;
		return t;
	}
}
int main()
{
	stack q1,q2,q3;
	q1.f=q2.f=q3.f=-1;
	q1.r=q2.r=q3.r=-1;
	q1.size=q2.size=q3.size=100;
	int n;int c=1;
	cin>>n;
	while(n!=-1)
	{
		enqueue(q1,n);
		enqueue(q3,n);
		c++;
		cin>>n;
	}
    n=c-1;
	for(int i=0;i<n;i++)
	{
		int min=999;
		for(int j=0;j<n-i;j++)
		{
			int t=dequeue(q1);
			if(min>t)
			min=t;
			enqueue(q1,t);
		}
		enqueue(q2,min);
		dequeue(q1);
	}
	while(q2.f!=-1)
	cout<<dequeue(q3)<<" "<<dequeue(q2)<<" ";
	return 0;
}