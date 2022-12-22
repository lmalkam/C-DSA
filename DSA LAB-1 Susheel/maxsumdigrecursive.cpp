#include<iostream>
using namespace std;

int maxdigsum(int n,int max,int sum){

    if(n==0){
         cout<<max<<" "<<sum;
         return 0;
    }
    else
        return maxdigsum(n/10,n%10>max?max=n%10:max=max,sum+n%10);
}

int main(){

    int n;
    cin>>n;

    maxdigsum(n,0,0);

     return 0;
}