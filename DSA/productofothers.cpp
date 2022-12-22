#include<iostream>
using namespace std;

int multiply(int *a,int n,int i,int count){

    if(i==count && count==n-1){
            return 1;
    }

    if(i==n-1)
    return a[n-1];

    if(i==count)
    return multiply(a,n,i+1,count)*1;

    return multiply(a,n,i+1,count)*a[i];

}

int index(int *a,int *b,int n,int i,int count){

    if(i==count){
    b[count]=multiply(a,n,0,count);
    if(count==n-1)
    return 0;
    index(a,b,n,0,count+1);
    }
    else
    return index(a,b,n,i+1,count);


}

int main(){
    
      int a[5],b[5];

      for(int i=0;i<5;i++)
      cin>>a[i];

      index(a,b,5,0,0);

      for(int i=0;i<5;i++){
          a[i]=b[i];
      cout<<a[i]<<" ";
      }

     return 0;
}