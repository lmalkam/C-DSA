#include<iostream>
using namespace std;

int print(int a[6][6],int i,int j,int m,int n){

    if(i<0 || j<0 || i>=6 || j>=6){
    return 0;
    }

    if(i==0 || j==0 || i==5 || j ==5){
    cout<<a[i][j]<<" ";
    print(a,i+1,j,m,n);
    print(a,i,j+1,m,n);
    print(a,i-1,j,m,n);
    print(a,i,j-1,m,n);
    }
}

int main(){
      int a[6][6]={10,13,14,21,23,
      11,9,22,2,3,
      12,8,1,5,4,
      15,24,7,6,20,
      16,17,18,19,25};

      print(a,0,0,6,6);


     return 0;
}