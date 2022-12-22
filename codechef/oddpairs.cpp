#include<iostream>
using namespace std;

void counter(int &count,int i,int j,int n)
{
    if(i==n+1 || j==n+1)
    return;
    if((i+j)%2!=0)
    count++;
    counter(count,i+1,j,n);
    counter(count,i,j+1,n);
}

int main(){
      
      int n;cin>>n;
      for(int i=0;i<n;i++)
      {
        int z;cin>>z;int count=0;
        counter(count,1,1,z);
        cout<<count<<endl;
      }


     return 0;
}