#include <iostream>
using namespace std;

int main()

{ 
    int n=4;

    int a[4]; 

    for(int i=0;i<4;i++){
          cin>>a[i];
      }

      for(int i=0;i<4;i++){
        int temp=a[i];
        a[i]=a[4-1-i];
        a[n-1-i]=temp;
    }
    cout<<endl;

    for(int i=0;i<4;i++){
          cout<<a[i];
      }



}