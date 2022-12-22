#include<iostream>
using namespace std;

void print(int a[],int n,int i,int j,int k,int count,bool flag){
    
    if(i==n)
    return;
    
    if(j==n)
    return print(a,n,i+1,i+1,k,0,1);
    
    if(flag==true){
    cout<<a[i]<<" ";
    count++;
    flag=false;
    }
    
    
    if(count==k)
    return print(a,n,i,j,k,0,1);
    
    if(i<n){
    cout<<a[j]<<" ";
    return print(a,n,i,j+1,k,count+1,0);
    }
    
}

int main(){
	int a[99];
	int i=0;int n=0;bool flag=true;
	while(i>=0){
		cin>>a[i];n++;
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[j]==a[k]){
					flag=false;
					break;
				}
			}
			if(flag==false)
			break;
		}
		if(flag==false)
		break;
		i++;
	}
    n=n-1;
    int k=a[n];
	
	print(a,n,0,0,k,0,1);
	
}