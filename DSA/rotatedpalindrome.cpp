#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
      string s;
      cin>>s;
      int flag;
      
      for(int i=0;i<s.length();i++){
          flag=0;
      rotate(s.begin(),s.begin()+1,s.end());

      string p=s;
      reverse(p.begin(),p.end());

      if(p==s){
          flag=1;
          break;
      }

      }
      

      cout<<flag;

     return 0;
}