#include<iostream>
using namespace std;

int back(int a[][99],int b[][99],int m,int n,int x,int y,int k,int sum){

    if(k==sum && x==m-1 && y==n-1)
    return 0;

    if(x>=m and y>=n)
    return 0;

    if(b[x+1][y]==0 && sum+a[x+1][y]<=k){
        b[x+1][y]==1;
        cout<<a[x+1][y]<<" ";
        back(a,b,m,n,x+1,y,k,sum+a[x+1][y]);
        b[x+1][y]==0;
    }
    if(b[x][y+1]==0 &&  sum+a[x][y+1]<=k){
        b[x][y+1]==1;
        cout<<a[x][y+1]<<" ";
        back(a,b,m,n,x,y+1,k,sum+a[x][y+1]);
        b[x][y+1]==0;
    }
}

int main(){
      

      int m,n;
      cin>>m>>n;

      int a[99][99];

      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              cin>>a[i][j];
          }
      }

      int b[99][99]={0};

      int k;
      cin>>k;
      back(a,b,m,n,0,0,k,0);

     return 0;
}