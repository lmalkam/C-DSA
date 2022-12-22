#include<bits/stdc++.h>
using namespace std;

void solution(){

    int n,x,y;
    cin>>n>>x>>y;

    if(y%x==0)
    {
        if(y/x<=n)
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
    else
    cout<<"NO"<<endl;

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}