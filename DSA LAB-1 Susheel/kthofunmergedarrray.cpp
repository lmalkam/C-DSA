#include<iostream>
#include<climits>
using namespace std;

void sorting(int a[],int b[], int c[],int n1,int n2,int n3,int i,int j,int k,int count,int output){

    if(count==0){
    cout<<output;
    return;
    }

    if(a[i]<b[j] and a[i]<c[k])
    return sorting(a,b,c,n1,n2,n3,i+1,j,k,count-1,a[i]);

    if(b[j]<a[i] and b[j]<c[k])
    return sorting(a,b,c,n1,n2,n3,i,j+1,k,count-1,b[j]);

    if(c[k]<b[j] and c[k]<a[i])
    return sorting(a,b,c,n1,n2,n3,i,j,k+1,count-1,c[k]);

}

int main(){

    int n1,n2,n3,i1=0,i2=0,i3=0;
	int a[20],b[20],c[20];
	cin>>a[i1];
	while(a[i1]!=-1){
		i1++;
		cin>>a[i1];
	}
	n1=i1;
	
	cin>>b[i2];
	while(b[i2]!=-1){
		i2++;
		cin>>b[i2];
	}
	n2=i2;
	
	cin>>c[i3];
	while(c[i3]!=-1){
		i3++;
		cin>>c[i3];
	}
	n3=i3;

	int k;
	cin>>k;

    sorting(a,b,c,n1,n2,n3,0,0,0,k,0);
      
     return 0;
}