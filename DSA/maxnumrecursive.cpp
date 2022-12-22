#include<iostream>
using namespace std;

int maxsum(int a[],int i,int n,int max){

    if(i==n-1)
      return a[i]>max?max=a[i]:max=max;
    else
      return maxsum(a,i+1,n,a[i]>max?max=a[i]:max=max);
      
}

int main(){

    int i=0,n=0;
      int a[100];
      while(i>=0){
          cin>>a[i];
          if(a[i]==-1)
              break;
          i++,n++;
      }

      int result=maxsum(a,0,n,0);

      cout<<result;

     return 0;
}