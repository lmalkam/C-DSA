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
        int a[3];
        for(int i=0;i<3;i++)
        cin>>a[i];

        for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
        {
            if(a[i]<a[j]){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
       
        int count=0;
        if(a[0]>=1){count++;a[0]--;}
        if(a[1]>=1){count++;a[1]--;}
        if(a[2]>=1){count++;a[2]--;}

        counter(a[0],a[1],a[2],count,0);

        cout<<count<<endl;
      }


     return 0;
}