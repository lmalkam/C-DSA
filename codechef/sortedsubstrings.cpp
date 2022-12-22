#include<bits/stdc++.h>
using namespace std;

void solution(){

    int n;cin>>n;
    string a;cin>>a;

    if(n==2)
    {
        if((a[1]==a[0]))
        cout<<0<<endl;
        else
        cout<<1<<endl;
        return;
    }

    int c1=0,c2=0;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            continue;
        }
        else
        {
            if(a[i]=='0')
            c1++;
            else
            c2++;
        }
    }

    if(a[n-1]==0)
            c1++;
            else
            c2++;

    cout<<min(c1,c2)<<endl;

}
int main(){
      int t;cin>>t;
      while(t--)solution();
      
     return 0;
}