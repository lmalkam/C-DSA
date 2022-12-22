#include<iostream>
using namespace std;

void maze(int a[8][8],int b[8][8],int n,int m,int x,int y){

    if(x==n && y==m){
    b[x][y]=1;
    cout<<1;
    return;
    }

    if(x<0 || y<0 || x>=8 || y>=8 || a[x][y]==0 || b[x][y]==1)
    return;

    b[x][y]=1;
    maze(a,b,n,m,x+1,y);
    maze(a,b,n,m,x,y+1);
    maze(a,b,n,m,x-1,y);
    maze(a,b,n,m,x,y-1);

}

int main(){
      

      int a[8][8]={ 0,0,0,0,0,0,0,0,

                  0,1,1,1,1,1,1,0,

                  0,1,0,1,0,0,0,0,

                  0,0,0,1,1,1,1,0,

                  0,1,0,0,0,0,1,0,

                  0,1,0,0,1,0,1,0,

                  0,1,1,1,1,0,1,0,

                  0,0,0,0,0,0,0,0 };

      int b[8][8]={0};

      int n,m,x,y;
      cin>>x>>y>>n>>m;

      maze(a,b,n,m,x,y);

      /*for(int i=0;i<8;i++){
          for(int j=0;j<8;j++){
              cout<<b[i][j];
          }
          cout<<endl;
      }*/

      if(b[n][m]!=1)
		cout<<"0";

        return 0;

}