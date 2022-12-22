#include<iostream>
using namespace std;

string seesay(int n){

    if(n==1)
    return "1";

    string str1=seesay(n-1);
    string str2="";

    for(int i=0;i<str1.length();i++)
    {
        int count=1;
        while(str1[i]=str1[i+1]){
            i++;count+1;
        }
        
    }



    return str2;
    
}

int main(){
      
      int n;
      cin>>n;

      cout<<seesay(n);


     return 0;
}