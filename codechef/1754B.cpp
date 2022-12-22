#include<bits/stdc++.h>
using namespace std;

void solution(){
    int n;
        cin>>n;
        
        int i = n / 2; 
        int j = n;
        if(n % 2 == 1) i = i + 1;
        
        
        
        while(i > 0) {
              cout<<i--<<" ";
              if(i == 0) break;
              cout<<j--<<" ";
        }
        
        if(n % 2 == 0) cout<<j;
        cout<<endl;
}
int main(){
      int t;cin>>t;
      while(t--)solution();
     return 0;
}