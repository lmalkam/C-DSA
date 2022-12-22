#include<bits/stdc++.h>
using namespace std;
struct STree
{
	int teen;
	int adult;
	int elder;
    int value;
};
STree consST(STree ST[],int A[],int si,int l,int r)
{
	if(l==r){
		ST[si].value=A[r];
        if(A[r]<20)
        ST[si].teen=1;
        else ST[si].teen=0;
        if(A[r]>=20 && A[r]<65)
        ST[si].adult=1;
        else ST[si].adult=0;
        if(A[r]>=66)
        ST[si].elder=1;
        else ST[si].elder=0;
		return ST[si];
	}
	int mid=(l+r)/2;
	ST[si].teen=consST(ST,A,2*si+1,l,mid).teen+consST(ST,A,2*si+2,mid+1,r).teen;
    ST[si].adult=consST(ST,A,2*si+1,l,mid).adult+consST(ST,A,2*si+2,mid+1,r).adult;
    ST[si].elder=consST(ST,A,2*si+1,l,mid).elder+consST(ST,A,2*si+2,mid+1,r).elder;
	return ST[si];
}

int adultinrange(STree s[],int si,int sl,int sr,int l,int r)
{
	if(l<=sl && r>=sr){
		return s[si].adult;
	}
	if(sl>r || sr<l){
		return 0;
	}
	int mid=(sl+sr)/2;
	return adultinrange(s,si*2+1,sl,mid,l,r)+adultinrange(s,si*2+2,mid+1,sr,l,r);
}
int teeninrange(STree s[],int si,int sl,int sr,int l,int r)
{
	if(l<=sl && r>=sr){
		return s[si].teen;
	}
	if(sl>r || sr<l){
		return 0;
	}
	int mid=(sl+sr)/2;
	return teeninrange(s,si*2+1,sl,mid,l,r)+teeninrange(s,si*2+2,mid+1,sr,l,r);
}
int elderinrange(STree s[],int si,int sl,int sr,int l,int r)
{
	if(l<=sl && r>=sr){
		return s[si].elder;
	}
	if(sl>r || sr<l){
		return 0;
	}
	int mid=(sl+sr)/2;
	return elderinrange(s,si*2+1,sl,mid,l,r)+elderinrange(s,si*2+2,mid+1,sr,l,r);
}
int main()
{
	int A[100];
	int i,n=0;
	cin>>i;
	while(i!=-1){
		A[n]=i;
		n++;
		cin>>i;
	}
	int si=0,l=0,r=n-1;
	STree s[200];
	consST(s,A,si,l,r);
	/*for(int i=0;i<40;i++){
		cout<<s[i].teen<<endl;
	}*/
	int n1,n2;
	cin>>n1>>n2;
	while(n1!=-1 && n2!=-1){
		cout<<teeninrange(s,si,l,r,n1,n2)<<" "<<adultinrange(s,si,l,r,n1,n2)<<" "<<elderinrange(s,si,l,r,n1,n2)<<" ";
		if( teeninrange(s,si,l,r,n1,n2) + adultinrange(s,si,l,r,n1,n2) > elderinrange(s,si,l,r,n1,n2)){
			cout<<"1";
		}
		else cout<<"0";
		cout<<endl;
		cin>>n1>>n2;
	}
	return 0;
}
// 9 12 17 18 20 25 34 45 49 50 55 64 67 68 75 80 84 85 -1