#include<iostream>
using namespace std;

int main(){
      int n;cin>>n;
      for(int i=0;i<n;i++)
      {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==1 || b==1 || c==1 || d==1)
        cout<<"OUT"<<endl;
        else
        cout<<"IN"<<endl;
      }


     return 0;
}