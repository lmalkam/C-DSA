#include<iostream>
#include<cmath>
using namespace std;

void bhago(int i,int j,int x,int y,int target,bool &flag)
{
    if(target==-1)
    return;

    if(i==x && j==y){
    if(target==0)
    flag=true;
    return;
    }

    if(i<0 || j<0 || i>pow(10,5) || j>pow(10,5))
    return;

    bhago(i+1,j,x,y,target-1,flag);
    bhago(i,j+1,x,y,target-1,flag);
    bhago(i-1,j,x,y,target-1,flag);
    bhago(i,j-1,x,y,target-1,flag);
}

int main(){
      
      int k;
      cin>>k;
      for(int i=0;i<k;i++){
        int a,b,c,d,n;
        cin>>a>>b>>c>>d>>n;

        bool flag=0;

        bhago(a,b,c,d,n,flag);

        if(flag)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
      }

     return 0;
}