#include<iostream>
using namespace std;

int main(){

      int m,n;
      cout<<"Enter the number of rows and coloumn : ";
      cin>>m>>n;

      int a[m][n];
      for(int i=1;i<=m;i++){
          for(int j=1;j<=n;j++){
              cin>>a[i][j];
          }
      }

      int rowstart=1,rowend=m,columnstart=1,columnend=n;

      while(rowstart<=rowend && columnstart<=columnend)
      {

          for(int column=columnstart; column<=columnend;column++)   
          cout<<a[rowstart][column]<<" ";

          rowstart++;

          for(int row=rowstart; row<=rowend;row++)
          cout<<a[row][columnend]<<" ";

          columnend--;

          for(int column=columnend; column>=columnstart;column--)
          cout<<a[rowend][column]<<" ";

          rowend--;

          for(int row=rowend; row>=rowstart;row--)
          cout<<a[row][columnstart]<<" ";

          columnstart++;

      }

     return 0;
}