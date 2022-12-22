#include<iostream>
using namespace std;

struct STree
{
    int value;
    int min1;
    int min2;
    int max;
    float avg;
};
STree consST(STree ST[],int A[],int B[],int si,int l,int r)
{
	if(l==r){
		ST[si].min1=A[r];
        ST[si].min2=B[r];
		return ST[si];
	}
	int mid=(l+r)/2;
	//ST[si].value=consST(ST,A,2*si+1,l,mid).value+consST(ST,A,2*si+2,mid+1,r).value;
    ST[si].min2= min(consST(ST,A,B,2*si+1,l,mid).min2,consST(ST,A,B,2*si+2,mid+1,r).min2);
    ST[si].min1= min(consST(ST,A,B,2*si+1,l,mid).min1,consST(ST,A,B,2*si+2,mid+1,r).min1);
   // ST[si].avg=(consST(ST,A,2*si+1,l,mid).value+consST(ST,A,2*si+2,mid+1,r).value)/(r-l+1);
	return ST[si];
}
int rangesum(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].value;
	if(sl>r || sr<l)
     return 0;
	int mid=(sl+sr)/2;
	return rangesum(ST,2*si+1,sl,mid,r,l) + rangesum(ST,2*si+2,mid+1,sr,r,l);
}

int rangemax(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].max;
	if(sl>r || sr<l)
    return 0;
	int mid=(sl+sr)/2;
	return max(rangemax(ST,2*si+1,sl,mid,r,l) , rangemax(ST,2*si+2,mid+1,sr,r,l));
}

int rangemin1(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].min1;
	if(sl>r || sr<l)
    return 999;
	int mid=(sl+sr)/2;
	return min(rangemin1(ST,2*si+1,sl,mid,r,l) , rangemin1(ST,2*si+2,mid+1,sr,r,l));
}

int rangemin2(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].min2;
	if(sl>r || sr<l)
    return 999;
	int mid=(sl+sr)/2;
	return min(rangemin2(ST,2*si+1,sl,mid,r,l) , rangemin2(ST,2*si+2,mid+1,sr,r,l));
}


float rangeavg(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].avg;
	if(sl>r || sr<l)
    return 0;
	int mid=(sl+sr)/2;
	return (rangemax(ST,2*si+1,sl,mid,r,l) + rangemax(ST,2*si+2,mid+1,sr,r,l))/2;

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


int update(STree ST[], int l, int r, int pos, int c, int i=0)
{
    if(pos<l || r<pos)
       return ST[i].value;
       
	if(l==r)
	{
		ST[i].value=c;
		return ST[i].value;
	}
	
	if(l<=pos && pos<=r) 
	{
		int mid=(l+r)/2;
		int x=update(ST, l, mid, pos, c, 2*i+1), y=update(ST, mid+1, r, pos, c, 2*i+2);
		
		ST[i].value=x+y;
	}
	return ST[i].value;
}


int main()
{
	int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int m;cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    cin>>b[i];
    STree ST1[100],ST2[100];

	 int l=0,r=n-1,k,sl,sr;
	
     int si=0;
	 consST(ST1,a,b,si,l,n-1);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(rangemin1(ST1,si,l,n-1,j,i)==rangemin2(ST1,si,l,m-1,j,i))
            {
                cout<<i<<" "<<j<<endl;
               // cout<<rangemin(ST1,si,l,n-1,j,i);
            }
        }
    }


    return 0;

}