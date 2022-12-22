#include<iostream>
using namespace std;

struct s9{
    int x;
    s9 *w;
};

struct s10{
    int y;
    s10 *z;
};

struct s8
{
    int u;
    s9 *t;
    s10 *v;
};

struct s7{
    char o;
    s8 *p;
    int n;
};

struct s6
{
    int r;
    s7 *q;
    s6*v;
};

struct s5
{
    int e;
    s6 *m;
};

struct s4
{
    s7 *j;
    s5 *k;
};

struct s3
{
    s4*g;
    s3*h;
    s5*i;
};

struct s2
{
    char e;
    s3*f;
};

struct s1
{
    int b;
    s1*a;
    s2*c;
    s1*d;
};



int main(){

    int b,r,u;
    cin>>b>>r>>u;

    s1 s;
    s.c=new(s2);
	s.c->f=new(s3);
	s.c->f->g=new(s4);
	s.c->f->i=new(s5);
	s.c->f->g->j=new(s7);
	s.c->f->i->m=new(s6);
	s.c->f->g->j->p=new(s8);
    s.c->f->g->j->p->t=new(s9);
    s.c->f->g->j->p->v=new(s10);

    if(u%2==0)
    {
        s.c->f->g->j->p->t->x=b;
        s.c->f->g->j->p->v->y=r;
    }
    else{
          s.c->f->g->j->p->t->x=r;
        s.c->f->g->j->p->v->y=b;
    }

    cout<<b<<" "<<r<<" "<<u<<" "<<s.c->f->g->j->p->t->x<<" "<<s.c->f->g->j->p->v->y;

     return 0;
}