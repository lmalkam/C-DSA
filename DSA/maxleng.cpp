#include<iostream>
using namespace std;

int main(){
      
      int i=0,n=0;
      int a[100];
      while(i>=0){
          cin>>a[i];
          if(a[i]==0)
              break;
          i++,n++;
      }
    
      int k;
      cin>>k;
      int sum,max=0;

      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              sum=0;
              for(int l=i;l<=j;l++){
                  sum+=a[l];
              }
              if(sum==k){
                  if(max<=j-i+1){
                      max=j-i+1;
                  }
              }
          }
      }

      cout<<max;


     return 0;
}