#include<iostream>
using namespace std;



int main(){

    int n=5;
      
      int a[n];

      for(int i=0;i<5;i++)
      cin>>a[i];

      remove(a,&n,0);

      for(int i=0;i<n;i++)
      cout<<a[i]<<" ";

     return 0;
}