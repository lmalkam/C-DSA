#include<iostream>
using namespace std;

void countsort(int a[],int index[],int sort[],int n,int max)
{
    for(int i=0;i<n;i++)
    {
        index[a[i]]+=1;
    }

    cout<<"check";

    for(int i=1;i<max-1;i++)
    {
        index[i]+=index[i-1];
    }

    cout<<"check";

    int i=n-1;
    while(i>=0)
    {
        sort[index[a[i]]-1]=a[i];
        index[a[i]]-=1;
        i-=1;
    }
    cout<<"check";
}

int main(){

    int a[100];
    int k,i=0;
    int max=0;
    while(i>=0){
    cin>>k;
    if(k==-1)break;
    if(max<k)max=k;
    a[i++]=k;
    }
    int sort[i];

    for(int j=0;j<i;j++)
    cout<<a[j]<<" ";

    cout<<i<<" "<< max;
    int index[max]={0};

    countsort(a,index,sort,i,max);

    for(int j=0;j<i;j++)
    cout<<sort[j]<<" ";

     return 0;
}