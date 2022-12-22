#include<iostream>
using namespace std;

int main(){
      int n;
      cin>>n;

      int a[99];

      for(int i=0;i<n;i++){
          a[i]=i+1;
      }

      int p[n-1];

      for(int i=1;i<n;i++){
          p[i-1]=a[i];
      }

      for(int i=1;i<=n;i++){

          
          cout<<"For "<<i+1<<endl;
          cout<<a[0];


      }


     return 0;
}