#include<iostream>
using namespace std;

void ways(int i,int n){
	
	if(i==5){
	cout<<i<<" "<<endl;
	return;
    }
	
	//cout<<n<<" ";
	
	if(i>5)
	return;
	
    if(i*3<=n){
    ways(i*3,n);
    cout<<i<<" ";
    }
    
    if(i*2<=n){
    ways(i*2,n);
    cout<<i<<" ";
    }
    
    if(i+1<=n){
    ways(i+1,n);
    cout<<i<<" ";
    }

}

int main(){
	
	int n;
	cin>>n;
	
	ways(1,n);
	
}