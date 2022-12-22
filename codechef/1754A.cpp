#include<bits/stdc++.h>
using namespace std;

void solution(){

    int n;string s;cin>>n>>s;
    
        int a[2]={0};
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]=='Q')
            st.push(s[i]);
            else
            {
            if(st.size()>0)
            st.pop();
            }
        }

        if(st.empty() || st.top()=='A' )
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}