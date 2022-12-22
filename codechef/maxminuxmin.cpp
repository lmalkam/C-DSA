#include<bits/stdc++.h>
using namespace std;

void solution(){


    int a,b,c;
    cin>>a>>b>>c;

    int maxx,minn;

    maxx=max(a,b);
    minn=min(b,c);
    maxx=max(b,c);
    minn=min(a,b);
    cout<<maxx-minn<<endl;

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}