#include<iostream>
using namespace std;

int main(){
      int n,n1,a[100],count,flag,max;cin>>n;
      for(int i=0;i<n;i++)
      {
        int b[999]={0};
        flag=0,count=0,max=-99;
        cin>>n1;
        for(int i=0;i<n1;i++)
        cin>>a[i];

        for(int i=0;i<n1;i++)
        {
            b[a[i]]++;
        }

        // for(int i=0;i<n1;i++)
        // {
        //     cout<<b[i]<<endl;
        // }

        for(int i=0;i<=999;i++)
        {
            if(max<b[i])
            max=b[i];
        }
    
        for(int i=0;i<=999;i++)
        {
            if(max==b[i])
            count++;  
        }
        if(count<=1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
      }


     return 0;
}