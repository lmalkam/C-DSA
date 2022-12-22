#include<iostream>
using namespace std;

struct arr{
    int a[100];
};

void sort(int k,struct arr ar[],int size[],int min,int counter,int ind[]){

    if(counter==0)
    return;
    int z;
    for(int i=0;i<k;i++){
        if(ind[i]<size[i]){
            if(ar[i].a[ind[i]]<min)
            {
                min=ar[i].a[ind[i]];
                z=i;
            }
        }
    }
    ind[z]++;
    cout<<min<<" ";
    return sort(k,ar,size,999999,counter-1,ind);
}

int main(){

    int k;
    cin>>k;
    arr ar[100];
    int size[k];
    int ind[k]={0};
    for(int i=0;i<k;i++){
        int j=0;
        cin>>ar[i].a[j];
        j++;
        while(j>0){
            cin>>ar[i].a[j];
            if(ar[i].a[j]==-1)
            break;
            j++;
        }
        size[i]=j;
    }
    
    int sum=0;
    for(int i=0;i<k;i++)
    sum+=size[i];

    sort(k,ar,size,999999,sum,ind);
    
     return 0;
}