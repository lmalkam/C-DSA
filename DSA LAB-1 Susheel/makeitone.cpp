#include<iostream>
using namespace std;

int makeitone(int n){

    cout<<n<<" ";

    if(n==1)
    return 0;
    
    if(n%2==0 )
    return makeitone(n/2);

    if(n%3==0)
    return makeitone(n/3);

    return makeitone(n-1);
}

int main(){
      
      int n;
      cin>>n;

      makeitone(n);

     return 0;
}