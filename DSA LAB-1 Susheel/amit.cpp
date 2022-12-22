#include<iostream>
using namespace std;
struct stack{
	int top;
	int size;
	int element[50];
    
};
void push(stack&s,int n){
	if(s.top==s.size){
		cout<<"stack full\n";
	}
	else{
		s.top++;
		s.element[s.top]=n;
	}}
	void pop(stack&s){
		if(s.top==-1){
			cout<<"Stack empty\n";
		}
		else
		s.top--;
	}
 
int main(){
	stack s;
	s.top=-1;
	int n;
	cout<<"Enter value of n \n";
	cin>>n;
	int arr[n],brr[n];
	cout<<"enter arr\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"enter brr\n";
	for(int i=0;i<n;i++){
		cin>>brr[i];
	}
	int j=0;
	for(int i=0;i<n;i++){
		push(s,arr[i]);
		if(arr[i]==brr[i]){
			pop(s);
			j++;
		}
		for(int k=s.top;k>=0;k--){
			if(s.element[s.top]==brr[j]){
				pop(s);
				j++;
			}
			else
			 break;
		}
			
		}
        if(s.top==-1){
	cout<<1;}
	else
	cout<<0;
	return 0;
	

	}