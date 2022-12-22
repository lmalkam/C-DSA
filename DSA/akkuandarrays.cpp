#include<iostream>
using namespace std;

struct STree
{
    int value[50];
};
void consST(STree ST[],int A[],int si,int l,int r)
{
	/*if(l==r){
		ST[si].value=A[r];
		return ST[si];
	}
	int mid=(l+r)/2;
	ST[si].value=consST(ST,A,2*si+1,l,mid).value+consST(ST,A,2*si+2,mid+1,r).value;
	return ST[si];*/
    if(l==r){
        ST[si].value[0]=A[l];
        return;
    }
    int mid=(l+r)/2;int i=0;
    for(int i=l;i<r;i++){
        ST[si].value[i]=A[i];i++;
    }
    consST(ST,A,2*i+1,l,mid);
    consST(ST,A,2*i+2,mid+1,r);
}

void rangemin2(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr){
        for(int i=0;i<r;i++){
            cout<<ST[si].value[i]<<" ";
            return;
        }
    }
	if(sl>r || sr<l)
    return;
	int mid=(sl+sr)/2;
    rangemin2(ST,2*si+1,sl,mid,r,l);
    rangemin2(ST,2*si+2,mid+1,sr,r,l);
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
	int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    STree ST[n];
    consST(ST,a,0,0,n);

    int i=0;
    while(i<n-1)
    {
        cout<<ST[i].value[i]<<endl;
        i++;
    }

    for(int i=0;i<1;i++)
    {
        int a,b,c;
        cin>>a>>b;
        rangemin2(ST,0,0,6,b,a);

    }

    return 0;
}