#include<iostream>
using namespace std;

string reverse(string s){

    if(s.length()==1)
    return s;
    else{
        char ch=s[0];
    return reverse(s.substr(1))+ch;
    }
}

int main(){

    string s;
    cin>>s;

    string ans=reverse(s);
    cout<<ans;

     return 0;
}