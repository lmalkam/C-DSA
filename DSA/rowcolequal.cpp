#include<iostream>
using namespace std;

void equalcol(int a[][99],int m,int n,int i,int j,int x, int count,bool flag){

    if(count==m){
        if(flag)
        cout<<j<<" "<<x<<" ";
        else
        cout<<x<<" ";
    return equalcol(a,m,n,0,j,x+1,0,0);
    }

    if(j==x)
    return equalcol(a,m,n,0,j,x+1,0,flag);

    if(j==n)
    return;

    if(i==m || x==n)
    return equalcol(a,m,n,0,j+1,j+2,0,flag);

    if(a[i][j]==a[i][x])
    return equalcol(a,m,n,i+1,j,x,count+1,flag);
    
    if(x<n)
    return equalcol(a,m,n,0,j,x+1,0,flag);

}

void equalrow(int a[][99],int m,int n,int i,int j,int x, int count,bool flag){

    if(count==n){
        if(flag)
        cout<<i<<" "<<x<<" ";
        else
        cout<<x<<" ";
    return equalrow(a,m,n,i,0,x+1,0,0);
    }

    if(i==x)
    return equalrow(a,m,n,i,0,x+1,0,flag);

    if(i==m)
    return;

    if(j==n)
    return equalrow(a,m,n,i+1,i+2,0,0,flag);


    if(a[i][j]==a[x][j])
    return equalrow(a,m,n,i,j+1,x,count+1,flag);
    
    if(x<m)
    return equalrow(a,m,n,i,0,x+1,0,flag);

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

      equalrow(a,m,n,0,0,0,0,1);
      cout<<endl;
      equalcol(a,m,n,0,0,0,0,1);
     return 0;
}