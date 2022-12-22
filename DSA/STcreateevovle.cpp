#include<iostream>
using namespace std;
int consST(int ST[],int A[],int si,int l,int r)
{
	if(l==r){
		ST[si]=A[r];
		ST[2*si+1]=0;
		ST[2*si+2]=0;
		return ST[si];
	}
	int mid=(l+r)/2;
	ST[si]=consST(ST,A,2*si+1,l,mid)+consST(ST,A,2*si+2,mid+1,r);
	return ST[si];
}
int rangesum(int ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si];
	if(sl>r || sr<l)
     return 0;
	int mid=(sl+sr)/2;
	return rangesum(ST,2*si+1,sl,mid,r,l) + rangesum(ST,2*si+2,mid+1,sr,r,l);
}
void update(int ST[],int si,int sl,int sr,int pos ,int diff)
{
	if(sl>pos || sr<pos) return;
	ST[si]=ST[si]+diff;
	if(sl!=sr){
		int mid=(sl+sr)/2;
		if(pos>=sl && mid>=pos)
        update(ST,2*si+1,sl,mid,pos,diff);
		if(pos>=mid+1 && pos<=sr)
        update(ST,2*si+2,mid+1,sr,pos,diff);
	}
}
int main()
{
	int A[100];
	int l=0,r=0,k;
	cin>>k;
	while(k!=-1){
		A[r]=k;r++;
		cin>>k;
	}
	r=r-1;
	int ST[50],si=0;
	consST(ST,A,si,l,r);
	for(int i=0;i<16;i++){
		cout<<ST[i]<<" ";
	}
	int n1,n2;
	cin>>n1>>n2;
	while(n1!=-1){
		cout<<rangesum(ST,0,l,r,n2,n1);
		cin>>n1>>n2;
	}
	int a,b;
	cin>>a>>b;
	int diff=b-A[a];
	cout<<diff<<endl;
	update(ST,si,0,5,a,diff);
	for(int i=0;i<16;i++){
		cout<<ST[i]<<" ";
	}
	
	return 0;
}