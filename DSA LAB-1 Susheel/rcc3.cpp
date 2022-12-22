#include<iostream>
using namespace std;

void print(int a[6][6],int i,int j,int m,int n,bool flag,int add){

    if(j==6){
          return print(a,1,5,m,n,0,add);
    }

    if(i==6){
          return;
         // return print(a,m-1,n-2,m,n,0,-1);
    }

    if(flag==false){
          cout<<a[i][j]<<" ";
          return print(a,i+add,j,m,n,0,add);
    }
    
    if(flag==true){
    cout<<a[i][j]<<" ";
    return print(a,i,j+add,m,n,flag,add);
    }
}

int main(){
      int a[6][6]={10,13,14,21,23,
      11,9,22,2,3,
      12,8,1,5,4,
      15,24,7,6,20,
      16,17,18,19,25};

      print(a,0,0,6,6,1,1);


     return 0;
}