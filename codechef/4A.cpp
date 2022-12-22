#include<bits/stdc++.h>
using namespace std;

void solution(){

    int n;cin>>n;
    if(n==2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(n%2==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

}
int main(){
      int t; //cin>>t;
      t=1;
      while(t--)solution();
      
     return 0;
}