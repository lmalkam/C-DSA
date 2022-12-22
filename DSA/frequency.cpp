#include<bits/stdc++.h>
using namespace std;

void digitfrequency(int n, int* ptr)
{
    if(n==0)
    return;
    else{
        int r = n%10;
        *(ptr+r)+=1;
        digitfrequency(n/10,ptr);
    }
}

int main()
{
    return 0;
    int a[100];
    int n;
    do{
        cin>>a[n];
        n++;
    }while(a[n-1]!=-1);
    n=n-1;
    int count[10] = {0};
    int *p = count;
    for(int i=0;i<n;i++)
    {
        digitfrequency(a[i],p);
    }
    for(int i=0;i<10;i++)
    {
        cout<<i<<" "<<count[i]<<endl;
    }
    return;
}