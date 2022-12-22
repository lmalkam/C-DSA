#include<iostream>
using namespace std;

bool palin(int a[],const int n,int &i){
    
    if(i==n-1)
    return 1;
    else{
    int t=a[i++];
    palin(a,n,i);
    if(t!=a[i]){
        return 0;
    }
    else
    i++;
    return 1;
    }
}

int main(){
      
      int n;cin>>n;int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];

      int z=0;

      cout<<palin(a,n,z);

     return 0;
}