#include<iostream>
using namespace std;

int knight(int i,int j,int x,int y){

    if(i==x || j==y)
    return 0;

    if(i==x-1 || j==y-1)
    return 1;

    return knight(i+2,j+1,x,y)+knight(i+2,j-1,x,y)+knight(i-2,j+1,x,y)+knight(i-2,j+1,x,y)+knight(i+1,j+2,x,y)+knight(i-1,j+2,x,y)+knight(i+1,j-2,x,y)+knight(i-1,j-2,x,y);
}

int main(){

    int i,j,x,y;

    cin>>i>>j>>x>>y;

    cout<<knight(i,j,x,y);
      


     return 0;
}