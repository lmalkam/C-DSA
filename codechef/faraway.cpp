#include<iostream>
using namespace std;

int main(){
      long long t;cin>>t;
      for(int i=0;i<t;i++)
      {
        long long n,m;cin>>n>>m;int a[n];long long sum=0;long long x;
        for(int j=0;j<n;j++)
            cin>>a[j];
            
        for(int j=0;j<n;j++)
        {
           if(a[j]<=m/2)
           x=m-a[j];
           else 
           x=a[j]-1;
           sum+=x;
        }
        cout<<sum<<endl;
      }
     return 0;
}