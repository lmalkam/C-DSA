#include<iostream>
using namespace std;

int main(){
      int n;cin>>n;
      for(int i=0;i<n;i++)
      {
        int x,y,z;cin>>x>>y>>z;

        if(x>y && x>z)
        cout<<"SETTER"<<endl;

        if(x<y && y>z)
        cout<<"TESTER"<<endl;

        if(z>y && x<z)
        cout<<"EDITORIALIST"<<endl;
      }

     return 0;
}