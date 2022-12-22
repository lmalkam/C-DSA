#include <iostream>
using namespace std;
void merge(int A[],int mid,int low,int high)
{
	int B[100];
	int l=low,j=mid+1,h=high,k=low;
	while(l<=mid && j<=h){
		if(A[l]<A[j]){
			B[k]=A[l];
			l++,k++;
		}
		else{
			B[k]=A[j];j++,k++;
		}
	}
	while(l<=mid){
		B[k]=A[l];l++,k++;
	}
	while(j<=h){
		B[k]=A[j];j++,k++;
	}
	for(int i=low;i<=high;i++){
		A[i]=B[i];
	}
}
void mergesort(int A[],int low,int high)
{
	if(low<high){
		int mid=(low+high)/2;
		mergesort(A,low,mid);
		mergesort(A,mid+1,high);
		merge(A,mid,low,high);
	}
}
int main()
{
	int A[100];
	int n,i=0,max=0;
	cin>>n;
	while(n!=-1){
		if(n>max) max=n;
		A[i]=n;
		i++;
		cin>>n;
	}
	mergesort(A,0,i-1);
	for(int a=0;a<i;a++){
		cout<<A[a]<<" ";
	}		
	return 0;
}
//2 3 2 4 5 6 7 8 10 4 -1