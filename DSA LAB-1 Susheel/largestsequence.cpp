#include<iostream>
using namespace std;

int main(){

    int i=0,n=1;
    int a[99];
    while(i>=0){
        cin>>a[i];
        i++;
        n++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
     return 0;
}