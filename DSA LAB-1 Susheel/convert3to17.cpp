#include<iostream>
using namespace std;

bool find(int a[],int key,int n)
{
    for(int i=0;i<n;i++){
    if(key==a[i])
    return false;
    }
    return true;
}

int ans[100];int n=999;

void finder(int a[],int i,int start,int end)
{
    if(end==start)
    {
        a[i++]=end;
        if(n>i){
        n=i;
        for(int j=0;j<i;j++)
        ans[j]=a[j];
        }
        return;
    }

    a[i++]=start;
    if(start*2<=17 and find(a,start*2,i))
    finder(a,i,start*2,end);
    if(start+1<=17 and find(a,start+1,i))
    finder(a,i,start+1,end);
    if(start-1>=0 and start-1<=17 and find(a,start-1,i))
    finder(a,i,start-1,end);
}

void print()
{
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}

int main(){
      
      int a[100];

      finder(a,0,3,17);

      print();


     return 0;
}