#include <iostream>
#include <cstring>
#include<iomanip>
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


int main()
{
	string entry[15];int k=0;
	for(int i=0;i<15;i++){
		cin>>entry[i];
		if(entry[i]=="-1"){
			k=i;
			break;
		}
	}

	int a[100];int n=0;
	for(int i=0;i<k;i++){
		string temp=entry[i];
		int number=stoi(temp);
		while(number>0){
			int digit=number%10;
			a[n++]=digit;
			number/=10;		
		}
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
		    if(a[j]<=a[i]){
		    	int temp=a[i];
		    	a[i]=a[j];
		    	a[j]=temp;
			}
	}
	
	frequency(a,&n,0,0,0);
			
	return 0;
}