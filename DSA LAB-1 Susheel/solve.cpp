#include<iostream>
using namespace std;

bool safe(int a[99][99],int n,int m,int x,int y,int k,int sum){

    if (x >= 0 && x < n && y >= 0 && y < m && sum+a[x][y]<=k )
        return true;
    return false;
}

bool back(int a[99][99],int b[99][99],int n,int m,int x,int y,int k,int sum){

    if(x==n-1 && y==m-1 and k==sum){
    b[x][y]=1;
    return 1;
    }

    if(safe(a,n,m,x,y,k,sum)==true){

        if(b[x][y]==1)
        return false;


        b[x][y]=1;

        
        cout<<a[x][y]<<" ";

        if(back(a,b,n,m,x+1,y,k,sum+a[x][y])){
        return true;
        }

        if(back(a,b,n,m,x,y+1,k,sum+a[x][y])){
        return true;
        }

        
        
        b[x][y]=0;
        return false;
    }
    else
    return false;

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

     cout<< back(a,b,m,n,0,0,k,0);
     return 0;
}