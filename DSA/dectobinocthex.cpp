#include<iostream>
using namespace std;

void decbinocthex(int n,int b){
    if(n==0)
    return;
    if(b==2){
        decbinocthex(n/2,b);
        cout<<n%2;
    }
    else if(b==8){
        decbinocthex(n/8,b);
        cout<<n%8;
    }
    else if(b==16){
        char output;
        output=55+n%16;
        decbinocthex(n/16,b);
        cout<<output;
    }
}

int main(){

    int n,b;
    cin>>n>>b;
    decbinocthex(n,b);
     return 0;
}