#include<iostream>
using namespace std;

void swap(int &a,int &b){
          int temp=a;
          a=b;
          b=temp;
}

void selection(int a[],int i,int j,int min){

    if(i==6)
    return;

    if(j==6){
    swap(a[min],a[i]);
    return selection(a,i+1,i+2,i+1);
    }

    if(a[j]<a[min])
    min=j;

    return selection(a,i,j+1,min);
}

void bubble(int a[],int i,int j){

    if(i==12)
    return;

    if(j==12-i+5)
    return bubble(a,i+1,6);

    if(a[j]>a[j+1])
    swap(a[j],a[j+1]);

    return bubble(a,i,j+1);
}

int main(){
      
      int a[12];

      for(int i=0;i<12;i++)
      cin>>a[i];

      selection(a,0,1,1);
      bubble(a,6,6);

      for(int i=0;i<12;i++){
      cout<<a[i]<<" ";
      if(i==5)cout<<endl;}

     return 0;
}