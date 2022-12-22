#include<iostream>
using namespace std;

void ways(int n,int temp){
	
	if(n==1){
	cout<<n<<" "<<endl;
	return;
    }
	
	int i=0;
	
	if(n<=0)
	return;
	
    if(n%3==0){
	cout<<n<<" ";
    ways(n/3,temp);
    i++;
    }

    if(i==1)
    cout<<temp;
    
    if(n%2==0){
    cout<<n<<" ";
    ways(n/2,temp);
    }
    
    if(n>0){
    cout<<n<<" ";
    ways(n-1,temp);

    }
    
    return;

}

int main(){
	
	int n;
	cin>>n;
	
	ways(n,n,0);
	
}