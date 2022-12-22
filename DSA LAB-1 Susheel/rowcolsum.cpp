#include<iostream>
using namespace std;

void colsum(int **a,int n,int m,int i,int j,int sum){

    if(j==m)
    return;

    if(i==n){
        cout<<sum<<" ";
    return colsum(a,n,m,0,j+1,0);
    }

    return colsum(a,n,m,i+1,j,sum+a[i][j]);
}


void rowsum(int **a,int n,int m,int i,int j,int sum){

    if(i==n)
    return;

    if(j==m){
    cout<<sum<<" ";
    return rowsum(a,n,m,i+1,0,0);
    }

    return rowsum(a,n,m,i,j+1,sum+a[i][j]);

}

int main(){
      
      int n,m;
      cin>>n>>m;

       int** a=new int*[n];
      for(int i=0;i<m;i++){
          a[i]=new int[m];
      }

      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              cin>>a[i][j];
          }
      }

      rowsum(a,n,m,0,0,0);
      cout<<endl;
      colsum(a,n,m,0,0,0);


     return 0;
}