#include<iostream>
using namespace std;

int main(){
      
      for(int n=6;n>=1;n--){
      for(int i=1;i<=2*n-1;i++){
          if(i<=n)
              cout<<i<<" ";
          if(i>n)
              cout<<2*n-i<<" ";
      }
      cout<<endl;
      }

     return 0;
}