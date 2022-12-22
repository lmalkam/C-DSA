#include<iostream>
using namespace std;

void check(int a[],int b[],int &count,int n,int m)
{



}

int main(){
    int n,m;
    int a[n],b[m];

    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];

    int count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++){
            check(a,b,count,n,m);
        }
    }
     return 0;
}