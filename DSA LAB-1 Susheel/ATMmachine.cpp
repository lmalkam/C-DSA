#include<iostream>
using namespace std;

int main(){
      int n;cin>>n;
      for(int i=0;i<n;i++)
      {
        int N,k;cin>>N>>k;int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<N;i++)
        {
            if(k>=a[i])
            {
                cout<<1;
                k=k-a[i];
            }
            else
            cout<<0;
        }
        cout<<endl;
      }


     return 0;
}