#include<iostream>
using namespace std;

void reverse(string s){

    if(s.length()==0)
    ;
    else
        reverse(s[0]+s.substr(1));
}

int main(){
      
      string s;
      cin>>s;

      reverse(s);


     return 0;
}