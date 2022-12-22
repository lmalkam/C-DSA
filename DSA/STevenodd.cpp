#include<iostream>
using namespace std;

struct STree
{
    int value;
    int even;
    int odd;
};

STree consST(STree ST[],int A[],int si,int l,int r)
{
	if(l==r){
		ST[si].value=A[r];
        if(A[r]%2==0){
        ST[si].even=1;
        ST[si].odd=0;
        }
        else{
        ST[si].even=0;
        ST[si].odd=1;
        }
		ST[2*si+1].value=0;
		ST[2*si+2].value=0;
		return ST[si];
	}
	int mid=(l+r)/2;
	ST[si].even=consST(ST,A,2*si+1,l,mid).even+consST(ST,A,2*si+2,mid+1,r).even;
    ST[si].odd=consST(ST,A,2*si+1,l,mid).odd+consST(ST,A,2*si+2,mid+1,r).odd;
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

int even(STree ST[],int si,int sl,int sr,int l,int r)
{
    if(sl>=l && r>=sr)
    {
        return ST[si].even;
    }
    if(sr<l || sl>r)
    {
        return 0;
    }
    //cout<<ST[si].even<<" "<<ST[si].odd<<endl;
    int mid=(sl+sr)/2;
    return even(ST,2*si+1,sl,mid,l,r)+even(ST,2*si+2,mid+1,sr,l,r);
}

int odd(STree ST[],int si,int sl,int sr,int l,int r)
{
    if(sl>=l && r>=sr)
    {
        return ST[si].odd;
    }
    if(sr<l || sl>r)
    {
        return 0;
    }
    //cout<<ST[si].even<<" "<<ST[si].odd<<endl;
    int mid=(sl+sr)/2;
    return odd(ST,2*si+1,sl,mid,l,r)+odd(ST,2*si+2,mid+1,sr,l,r);
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
	STree ST[50];
    int si=0;
	consST(ST,A,si,l,r);
    l=0;

    // cout<<ST[0].value<<" ";int i=0;
    // while(i<r)
    // {
    //     cout<<ST[i*2+1].value<<" ";
    //     cout<<ST[i*2+1].even<<" "<<ST[i*2+1].odd<<endl;
    //     cout<<ST[i*2+2].value<<" ";
    //     cout<<ST[i*2+2].even<<" "<<ST[i*2+2].odd<<endl;
    //     i++;
    // }
	int n1,n2;
	cin>>n1>>n2;
	while(n1!=-1 && n2!=-1){
		cout<<even(ST,0,l,r,n1,n2)<<" "<<odd(ST,0,l,r,n1,n2)<<endl;
		cin>>n1>>n2;
	}
	
	return 0;
}