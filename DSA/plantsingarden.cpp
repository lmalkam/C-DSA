#include<iostream>
using namespace std;

struct pos
{
    int i,j;
};

struct stack
{
    int f,r,s;
    pos que[100];
};

void enqueue(stack &q,pos x){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else
        q.r=(q.r+1)%q.s;
        q.que[q.r].i=x.i;
        q.que[q.r].j=x.j;
    }
}

pos dequeue(stack &q){
    pos t;
    if(q.f==-1)
    return t;
    else{
        t=q.que[q.f];
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

int main(){
      
      stack q;q.f=-1,q.r=-1;
      q.s=50;
      pos plants[100];

      cin>>plants[0].i;
      cin>>plants[0].j;

      int n=0;
      while(plants[n].i!=-1 && plants[n].j!=-1){
          cin>>plants[++n].i;
          cin>>plants[n].j;
      }

      enqueue(q,plants[0]);

      for(int x=1;x<n;x++){
          if(q.que[q.r].i<plants[x].i)
              cout<<"";
          else
          enqueue(q,plants[x]);
      }

      while(q.f!=-1){
          pos output=dequeue(q);
          cout<<output.i<<" "<<output.j<<" ";
      }

     return 0;
}