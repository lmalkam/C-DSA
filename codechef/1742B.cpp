#include<bits/stdc++.h>
using namespace std;

void solution(){

    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    set<int>s;

    for(int i=0;i<n;i++)
    {
        auto pos=s.find(a[i]);
        if(pos!=s.end())
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            s.insert(a[i]);
        }
    }

    cout<<"YES"<<endl;
    return;




}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}