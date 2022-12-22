#include<iostream>
using namespace std;

int main(){
      
      int i=0,n=0;
      int a[100];
      while(i>=0){
          cin>>a[i];
          if(a[i]==-1)
              break;
          i++,n++;
      }

      if(a[0]==0){
          cout<<"-1";
          return 0;
      }

      int count=a[0],z,jump=0,maxreach=a[0];

      for(int i=0;i<n;i++){
          maxreach=max(maxreach,i+a[i]);
          count--;
          if(count==0){
              jump++;
              count=maxreach-i;
          }
          
      }

      cout<<jump;


     return 0;
}