#include<iostream>
using namespace std;

void counter(int &r,int &g,int &b,int &count,int flag)
{
    if(flag==1)
    {
        count++;
        return;
    }

    if(r>=1 && g>=1){
    counter(r,g,b,count,flag+1);r--;g--;
    }
    if(b>=1 && g>=1){
    counter(r,g,b,count,flag+1);
    g--;b--;
    }
    if(r>=1 && b>=1){
    counter(r,g,b,count,flag+1);
    r--,b--;
    }
}

int main(){
      int t;cin>>t;
      for(int i=0;i<t;i++)
      {
        int r,g,b;cin>>r>>g>>b;int count=0;
        if(r>=1){count++;r--;}
        if(g>=1){count++;g--;}
        if(b>=1){count++;b--;}

        counter(r,g,b,count,0);

        cout<<count<<endl;
      }


     return 0;
}