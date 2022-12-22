#include<iostream>
using namespace std;

int cal(int a[],int i,int j)
{
    int small=9999;
    for(int z=i;z<=j;z++)
    if(small>a[z])
    small=a[z];
    return small*(j-i+1);
}

int main(){
      int n;cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];

      int max=0;

      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
            if(max<cal(a,i,j))
            max=cal(a,i,j);
        }
      }

      cout<<max;

     return 0;
}