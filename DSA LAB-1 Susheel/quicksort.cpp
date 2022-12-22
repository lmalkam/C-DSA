#include <iostream>
using namespace std;
int part(int A[],int low,int high)
{
	int P=A[low];
	int l=low+1;
	int h=high;
	
	while(l<h){
		while(A[l]<=P){
			l++;
		}
		while(A[h]>P){
			h--;
		}
		if(l<h){
			int temp=A[l];
			A[l]=A[h];
			A[h]=temp;
		}
	}
	int temp=A[low];
	A[low]=A[h];
	A[h]=temp;
	return h;
}
void quicksort(int A[],int low,int high)
{
	if(low<high){
		int k=part(A,low,high);
		quicksort(A,low,k-1);
		quicksort(A,k+1,high);
	}
}
int main()
{
	int A[100];
	int n,i=0;
	cin>>n;
	while(n!=-1){
		A[i]=n;
		i++;
		cin>>n;
	}
	
	int low=0,high=i-1;
	quicksort(A,low,high);
	for(int j=0;j<i;j++){
		cout<<A[j]<<" ";
	}
	return 0;
}
//572 83 49 38 22 6 172 703 949 27 -1