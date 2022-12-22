#include<bits/stdc++.h>
using namespace std;

long long fact(long long int n)
{
    if(n==1)
    return 1;
    return fact(n-1)*n;
}

void solution(){

    long long n,k;cin>>n>>k;long long a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    long long sum=0;

    for(int i=0;i<n;i++)
    sum+=fact(a[i]);

    if(sum%fact(k)==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;


}
int main(){
      int t;t=1;
      while(t--)solution();
      
     return 0;
}