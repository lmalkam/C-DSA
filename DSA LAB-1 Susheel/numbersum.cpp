#include<iostream>
using namespace std;

void decrease(int n,int sum)
{
    if(n==0){
        if(sum>9)
        return decrease(sum,0);
        else{
        cout<<sum;
        return;
        }
    }
    return decrease(n/10,sum+n%10);
}

int main(){
      
      int n=1234;

      decrease(n,0);

     return 0;
}