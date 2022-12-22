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

    
      stack q;q.f=-1;q.r=-1;q.size=50;
      
      int a;
      int i=0,m;
      while(i>=0){
          cin>>a;
          enque(q,a);
          if(a==-1)
          break;
          i++;
      }m=++i;

      for(int i=0;i<m;i++){
          int k=deque(q);
          for(int j=0;j<m;j++){
              int l=deque(q);
              if(l==-1){
                  enque(q,k);
                  enque(q,l);
                  break;
              }
              if(k>l){
                  enque(q,l);
              }
              else{
                  enque(q,k);
                  k=l;
              }
          }
      }

      for(int i=0;i<m-1;i++){
          cout<<deque(q)<<" ";
      }


     return 0;
}