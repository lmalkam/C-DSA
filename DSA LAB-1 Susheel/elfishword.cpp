#include<iostream>
using namespace std;

bool check(string s,string str1,int i,int j){

    if(j==str1.length())
        return true;

    if(i==s.length())
    return false;

    if(s[i]==str1[j])
    return check(s,str1,0,j+1);
    else
    return check(s,str1,i+1,j);

}

int main(){
    int a[5];
      for(int i=0;i<5;i++){
          string s;
          cin>>s;

          string str1="elf";

          a[i]=check(s,str1,0,0);
      }
    
    for(int i=0;i<5;i++)
    cout<<a[i]<<endl;

    return 0;

}