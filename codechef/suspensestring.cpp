#include<bits/stdc++.h>
using namespace std;

void solution(){

    stack<int> st;
    int num[]={2,7,3,5,4,6,8};
    int ans[7]={-1};

    for(int i=0;i<7;i++)
    {
        int j=i;
        while(!st.empty() && st.top()>num[i])
        {
            ans[i]=st.top();
            st.pop();
        }
        i=j;
        st.push(num[i]);
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}