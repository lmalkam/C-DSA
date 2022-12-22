#include<iomanip>
#include<iostream>
using namespace std;

void remove(int a[],int *n, int i){

    if(i==*n){
    *n=*n-1;
    return;
    }
    
        a[i]=a[i+1];
    return remove(a,n,i+1);

}

void frequency(int *a,int *n,int i,int j,int count){

    if(i==*n)
    return;

    if(j==*n){
        cout<<a[i]<<setw(7)<<count<<endl;
    return frequency(a,n,i+1,0,0);
    }

    if(i==j)
    return frequency(a,n,i,i+1,count+1);

    if(a[i]==a[j]){
    remove(a,n,j);
    return frequency(a,n,i,i+1,count+1);
    }

    return frequency(a,n,i,j+1,count);
}

int main(){

    int a[99];
    int i=0,n=0,count=0;;
    while(i>=0){
        cin>>a[i];
        if(a[i]==-1)
        break;
        i++,n++;
    }

    frequency(a,&n,0,0,0);
      
     return 0;
}