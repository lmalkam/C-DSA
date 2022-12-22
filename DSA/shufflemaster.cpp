#include<iostream>
using namespace std;

void suffle(int a[],int n){

    if(n==1){
      for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
      return 0;
    }
    else{

    }


}

int main(){
      int n;cin>>n;int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];

      shuffle(a,n);

      int b[n],c[n];
      int x=0,y=0;

      for(int i=0;i<n;i++){
          if(i%2==0)
          b[x++]=a[i];
          else
          c[y++]=a[i];
      }


     return 0;
}