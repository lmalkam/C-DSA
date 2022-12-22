#include <iostream>
using namespace std;
struct stack
{
	int size;
	int elements[50];
	int top;
};
void push(stack &A,int x)
{
	if(A.top==(A.size-1)) cout<<"Stack is empty";
	A.top=A.top + 1;
	A.elements[A.top]=x;
}
int pop(stack &B)
{
	if(B.top==-1){
		return 0;
	}
	else{
		return B.elements[B.top--];
	}
}
int sum(stack &A,stack &B,stack &C,int s1,int s2,int s3)
{
	if(s1==s2 && s2==s3){
        return s1;
	}

    if(s1>s2 && s1>s3)
    {
        int t=pop(A);
        s1=s1-t;
    }

    if(s2>s1 && s2>s3)
    {
        int t=pop(B);
        s2=s2-t;
    }

    if(s3>s1 && s3>s2)
    {
        int t=pop(C);
        s3=s3-t;
    }

    return sum(A,B,C,s1,s2,s3);
}
void print(stack &S)
{
	if(S.top==-1) return;
	else{
		int k=pop(S);
		print(S);
		cout<<k<<" ";
	}
}
int main()
{
	stack A,B,C;
	int n1,n2,n3,s1=0,s2=0,s3=0;
	A.top=-1,B.top=-1,C.top=-1,A.size=100,B.size=100,C.size=100;
	cin>>n1;
	while(n1!=-1){
		push(A,n1);s1=s1+n1;
		cin>>n1;
	}
	cin>>n2;
	while(n2!=-1){
		push(B,n2);s2=s2+n2;
		cin>>n2;
	}
	cin>>n3;
	while(n3!=-1){
		push(C,n3);s3=s3+n3;
		cin>>n3;
	}
	int sumfinal=sum(A,B,C,s1,s2,s3);
	
	print(A);cout<<endl;
	print(B);cout<<endl;
	print(C);cout<<endl;
    cout<<sumfinal;
    
	
	
	return 0;
}