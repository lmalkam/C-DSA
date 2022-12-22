#include<iostream>
using namespace std;

struct pos
{
    int x,y;
    char ch;
};


struct stack
{
	int f;
	int r;
	int size;
	pos element[100];
};
void enque(stack &q,pos x)
{
	if((q.r+1)%q.size==q.f)
	return;
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
		q.element[q.r].x=x.x;
        q.element[q.r].y=x.y;
        q.element[q.r].ch=x.ch;
	}
}
pos deque(stack &q)
{    
    pos t;
	if(q.f==-1)
	return t;
	else
	{
		t=q.element[q.f];
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

int eval(pos i){
    if(i.ch=='A')
    return i.x+i.y;
    if(i.ch=='S')
    return i.x-i.y;
    if(i.ch=='M')
    return i.x*i.y;
    if(i.ch=='D')
    return i.x/i.y;
}

int main(){

    int a,b;
    char ch;

    stack q;q.f=-1;q.r=-1;q.size=50;

    int i=0,n;
    while(i>=0){
         cin>>a>>b>>ch;
         if(a==-1 && b==-1 && ch=='#')
         break;
         pos temp;temp.ch=ch;temp.x=a;temp.y=b;
         enque(q,temp);
         i++;
    }n=i;

    while(q.f!=-1){
    cout<<eval(deque(q))<<endl;}

     return 0;
}