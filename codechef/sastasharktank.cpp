#include<iostream>
using namespace std;

int main(){
      int n;
       cin>>n;

       for(int i=0;i<n;i++){
           int a,b;
           cin>>a>>b;

           if(a*100/10 == b*100/20)
           cout<<"ANY";
           else if(a*100/10>b*100/20)
           cout<<"FIRST";
           else
           cout<<"SECOND";
       }


     return 0;
}