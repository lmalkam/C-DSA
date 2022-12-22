#include<iostream>
using namespace std;

struct pos
{
    int x;
    int y;
};

struct stack
{
    int f,r,s;
    pos que[100];
};

void enqueue(stack &q,int a,int b){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else
        q.r=(q.r+1)%q.s;
       // cout<<a<<" "<<b<<" ";
        q.que[q.r].x=a;
        q.que[q.r].y=b;
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

void turnpostive(stack &q,int a[4][5]){

    pos t=dequeue(q);
    if(a[t.x+1][t.y]<0 && t.x+1<4)
    a[t.x+1][t.y]=-1*a[t.x+1][t.y];
    if(a[t.x][t.y+1]<0 && t.y+1<5)
    a[t.x][t.y+1]=-1*a[t.x][t.y+1];
    if(a[t.x-1][t.y]<0  && t.x-1>=0)
    a[t.x-1][t.y]=-1*a[t.x-1][t.y];
    if(a[t.x][t.y-1]<0 && t.y-1>=0)
    a[t.x][t.y-1]=-1*a[t.x][t.y-1];
    
    return;
}

int main(){

    stack q;q.f=-1;q.r=-1;q.s=50;

    int a[4][5]={-1,-9,0,-1,0,
    -8,-3,-2,9,-7,
    2,0,0,-6,0,
    0,-7,-3,5,-4,}   ;

    int count=0;bool flag=true;
    while(flag==true){
    flag=false;
    count++;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0){
                enqueue(q,i,j);
            }
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]>0)
            turnpostive(q,a);
        }
    }

   for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]<0){
                flag=true;
            }
        }
    }
    }

    cout<<count;

     return 0;
}