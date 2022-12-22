#include<iostream>
using namespace std;


bool check(string s,int i,int c)
{
    if(c>2)
    return true;
    if(i==s.length())
    return false;
    if(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='e')
    return check(s,i+1,c+1);
    return check(s,i+1,0);
}


int main(){
      int n;cin>>n;
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;

        int l=s.length();

        bool flag=false;

        if(check(s,0,0))
        cout<<"HAPPY"<<endl;
        else
        cout<<"SAD"<<endl;
      }

     return 0;
}