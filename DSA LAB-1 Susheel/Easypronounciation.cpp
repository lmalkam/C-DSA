#include<iostream>
using namespace std;

bool check(string s,int n,int i,int c)
{
    if(i<=n){

        if(c>=4)
        return false;

        if(i==n)
        return true;

        if(n<=3){
        return true;
        }
        
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        return check(s,n,i+1,0);

        return check(s,n,i+1,c+1);
    }
}

int main(){

      int x;cin>>x;
      for(int i=0;i<x;i++){
        int n;cin>>n;
      string s;cin>>s;
      
      if(check(s,n,0,0))cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
      }
     return 0;
}