#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        long long int m;
        cin>>m;int c=0;
        int x=0;int count=0;
        while(m>9){
            x=0;
        while(pow(2,x)<m)
        x++;
        x--;c++;
        m=m-pow(2,x);
        }
        if(m==1)cout<<1+c<<endl;
        if(m==2)cout<<0+c<<endl;
        if(m==3)cout<<1+c<<endl;
        if(m==4)cout<<0+c<<endl;
        if(m==5)cout<<1+c<<endl;
        if(m==6)cout<<1+c<<endl;
        if(m==7)cout<<2+c<<endl;
        if(m==8)cout<<0+c<<endl;
        if(m==9)cout<<1+c<<endl;
        if(m==0)cout<<0<<endl;
        
    }


     return 0;
}