#include<iostream>
using namespace std;

int getmax(int a[],int i,int k)
{
    int max=-999;
    for(int j=i;j<i+k;j++)
    if(max<=a[j])
    max=a[j];
    return max;
}

int main(){
      int n;cin>>n;int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];
      int k;cin>>k;

      for(int i=0;i<n-k+1;i++)
      {
        int x=getmax(a,i,k);
        cout<<x<<" ";

      }


     return 0;
}