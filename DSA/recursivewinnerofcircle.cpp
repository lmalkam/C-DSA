#include<iostream>
using namespace std;

void remove(int a[],int *n, int i){

    if(i==*n+1){
    *n=*n-1;
    return;
    }

    a[i]=a[i+1];
    return remove(a,n,i+1);
}

void winner(int a[],int *n,int og,int i,int k,int count){

    if(*n==1){
    cout<<a[*n];
    return;
    }


    if(count==k){
    remove(a,n,i);
    return winner(a,n,og,i-1,k,0);  
    }

     if(i>*n)
    return winner(a,n,og,1,k,count+1);

    return winner(a,n,og,i+1,k,count+1);

}

int main(){
      
      int n,k;
      cin>>n>>k;
      int a[n];

      for(int i=1;i<=n;i++)
      a[i]=i;

      winner(a,&n,n,0,k,0);


     return 0;
}