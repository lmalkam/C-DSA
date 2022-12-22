#include<iostream>
using namespace std;

struct trnode
{
	char d;
	trnode* sub;
	trnode* next;
};

typedef trnode* ll; 

void Lcreate(ll &l, char n)
{
	l=new(trnode);
	l->d=n;
	l->next=NULL;	
}

ll end(ll l)
{
	if(l->next==NULL)
		return l;
	return end(l->next);
}

void addel(ll &l, char n)
{
	if(l==NULL)
	{
	    Lcreate(l, n);
	}
	else
	{
		ll t, e;
		Lcreate(t, n);
		e=end(l);
		e->next=t;
	}	
}

void construct(ll &l, char c)
{
	if(c=='{')
	{
	    addel(l, c);
		ll t=NULL;
	    t=new(trnode);
	    cin>>c;
	    t->d=c;
    
        ll e=end(l);
		e->sub=t;
		cin>>c;
		while(c!='}')
		{
			construct(t, c);
			cin>>c;
		}
	}
	else if(c=='}')
    {
    	return;
	}
	else
	{
		addel(l, c);
	}
}

void print(ll l)
{
	if(l==NULL)
	{
		cout<<"} ";
		return;
	}
	cout<<l->d<<" ";
	if(l->d=='{')
	{
 		print(l->sub);	
	}
	
	print(l->next);
}

int main()
{
	ll L=NULL;	char s; cin>>s; cin>>s;
    L=new(trnode);
    L->d=s;
    cin>>s;
	while(s!='#') //{AB{CDE}F{G{HIJ}K}LM}#
	{
		construct(L, s);
		cin>>s;
	}
    
    cout<<'{'<<" ";
    print(L);
	
	return 0;
}