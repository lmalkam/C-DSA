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

    if(a[j]<a[min])
    min=j;

    if(j==6){
    swap(a[min],a[i]);
    return selection(a,i+1,i+2,min);
    }
    
    return selection(a,i,j+1,min);
}

void bubble(int b[],int i,int j){   

    if(i==6)
    return;

    if(j==6-i)
    return bubble(b,i+1,0);

    if(b[j]>b[j+1])
    swap(b[j],b[j+1]);

    return bubble(b,i,j+1);
}

int main(){
      
      int a[6],b[6];

      for(int i=0;i<6;i++)
      cin>>a[i];

      for(int i=0;i<6;i++)
      cin>>b[i];

      selection(a,0,1,0);
      bubble(b,0,0);

      for(int i=0;i<6;i++)
      cout<<a[i]<<" ";

      cout<<endl;

      for(int i=0;i<6;i++)
      cout<<b[i]<<" ";

     return 0;
}