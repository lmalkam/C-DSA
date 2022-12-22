#include<iostream>
using namespace std;

void print(int n,int store,int flag){

    if(n==1 || n==0){
    return;
    }

    
        cout<<n-1<<" ";
        print(n-2,store,flag);
        cout<<n-2<<" ";
    


    

    
}

int main(){
      
      int n;
      cin>>n;

      print(n,n,0);

     return 0;
}