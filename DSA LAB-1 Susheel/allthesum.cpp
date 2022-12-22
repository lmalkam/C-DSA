#include<iostream>
using namespace std;


int countpath(int i, int j,int n,int m){

    if(i==n || j==m)
    return 0;

    if(i==n-1 || j==m-1)
    return 1;

    int one=countpath(i+1,j,n,m);
    int two=countpath(i,j+1,n,m);

    cout<<one<<" "<<two;

    return one+two;
}

int main(){
      
    cout<<countpath(0,0,3,3);

     return 0;
}