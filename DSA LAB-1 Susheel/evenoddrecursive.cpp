#include<iostream>
using namespace std;

void print(int n,int i,int temp){

    if(i==n+1){
    cout<<endl;
    return;
    }

    if(i%2==0)
    cout<<i<<" ";
    print(n,i+1,temp);
    if(i%2!=0){
    cout<<temp-i<<" ";
    }
}

int main(){
      
      int n;
      cin>>n;

      int temp;

      n%2!=0?temp=n+1:temp=n;

      print(n,1,temp);

     return 0;
}