#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
      
      string s;
      cin>>s;

      rotate(s.begin(),s.begin()+1,s.end());

      cout<<s<<s.length();


     return 0;
}