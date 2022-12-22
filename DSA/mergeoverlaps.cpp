#include<iostream>
using namespace std;

int main(){

    int a[99];
    int i=0,n=1,count=0;;
    while(i>=0){
        cin>>a[i];
        if(a[i]==-1)
        count++;
        if(count==2)
        break;
        i++,n++;
    }
    n=n-2;

    int b[99];

    int z=0;
    b[0]=a[0];
    z++;
    int max=0;
    for(int i=0;i<n;i++){
        if(max<a[i])
        max=a[i];
        if((i+2)%2!=0){
            if(a[i]<a[i+1] && a[i]>max){
                b[z]=a[i];
                z++;
            }

        }
    }

    for(int i=0;i<z;i++)
    cout<<b[i]<<" ";


     return 0;
}