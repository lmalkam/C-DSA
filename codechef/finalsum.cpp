#include<bits/stdc++.h>
using namespace std;

void final(int i,int  j,int a[],int n)
{
    if(i%2==0)
    for(int k=i;k<=j;k++)
    {
        if(k%2==0)
        a[i]+=1;
        else
        a[i]-=1;
    }
    else
    for(int k=i;k<=j;k++)
    {
        if(k%2==0)
        a[i]-=1;
        else
        a[i]+=1;
    }

}

void solution(){

    long int n,q;
    cin>>n>>q;
    int a[n];

    for(int i=1;i<=n;i++)
    cin>>a[i];

    final(0,0,a,n);

    for(int z=0;z<q;z++)
    {
        int x,y;cin>>x>>y;
        final(x,y,a,n);
    }

    int sum=0;

    for(int i=1;i<=n;i++)
    sum+=a[i];

    cout<<sum<<endl;

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}