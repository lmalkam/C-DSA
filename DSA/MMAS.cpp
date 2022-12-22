#include<iostream>
using namespace std;

struct STree
{
    int value;
    int min;
    int max;
    float avg;
};
STree ST[10000];

STree consST(STree ST[],int A[],int si,int l,int r)
{
	if(l==r){
		ST[si].value=A[r];
		ST[si].max=A[r];
        ST[si].min=A[r];
        ST[si].avg=A[r];
		return ST[si];
	}
	int mid=(l+r)/2;
	ST[si].value=consST(ST,A,2*si+1,l,mid).value+consST(ST,A,2*si+2,mid+1,r).value;
    ST[si].max=max(consST(ST,A,2*si+1,l,mid).max,consST(ST,A,2*si+2,mid+1,r).max);
    ST[si].min=min(consST(ST,A,2*si+1,l,mid).min,consST(ST,A,2*si+2,mid+1,r).min);
    ST[si].avg=consST(ST,A,2*si+1,l,mid).avg+consST(ST,A,2*si+2,mid+1,r).avg/(r-l+1);
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
	return max(rangemax(ST,2*si+1,sl,mid,r,l),rangemax(ST,2*si+2,mid+1,sr,r,l));
}

int rangemin(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].min;
	if(sl>r || sr<l)
    return 999;
	int mid=(sl+sr)/2;
	return min(rangemin(ST,2*si+1,sl,mid,r,l) , rangemin(ST,2*si+2,mid+1,sr,r,l));
}
int rangeavg(STree ST[],int si,int sl,int sr,int r,int l)
{
	if(l<=sl && r>=sr) 
    return ST[si].avg;
	if(sl>r || sr<l)
    return 0;
	int mid=(sl+sr)/2;
	return (rangemax(ST,2*si+1,sl,mid,r,l) + rangemax(ST,2*si+2,mid+1,sr,r,l))/(sr-sl+1);
}

void update(STree ST[],int si,int sl,int sr,int pos ,int diff)
{
	if(sl>pos || sr<pos) return;
	ST[si].value=ST[si].value+diff;
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

   //- cout<<s;

    // cout<<i<<endl;

	 int l=0,r=n-1,k,sl,sr;
	
     int si=0;
	 consST(ST,a,si,l,r);
  //  l=0;

    // cout<<ST[0].value<<" ";i=0;
    // while(i<r)
    // {
    //     cout<<ST[i*2+1].value<<" ";
    //     cout<<ST[i*2+2].value<<" "<<endl;
    //     i++;
    // }
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int q;cin>>q;

        switch(q)
        {
            case 0:
            {
                int ind,x;cin>>ind>>x;
                int diff=x-a[ind];
                a[ind]=x;
                update(ST,l,r,ind,x,diff);
                break;
            }
            case 2:
            {
                cin>>sl>>sr;
                cout<<rangemax(ST,si,l,r,sr,sl)<<endl;
                break;
            }
            case 1:
            {
                cin>>sl>>sr;
                cout<<rangemin(ST,si,l,r,sr,sl)<<endl;
                break;
            }
            case 3:
            {
                cin>>sl>>sr;
                cout<<rangesum(ST,si,l,r,sr,sl)<<endl;
                break;
            }
            case 4:
            {
                cin>>sl>>sr;
                cout<<rangeavg(ST,si,l,r,sr,sl)<<endl;
                break;
            }

        }

    }

    // cout<<ST[0].value<<" ";int i=0;
    // while(i<r)
    // {
    //     cout<<ST[i*2+1].value<<" ";
    //     cout<<ST[i*2+2].value<<" "<<endl;
    //     i++;
    // }
   // int sl,sr;
   // cin>>sl>>sr;

  //  cout<<rangemax(ST,si,l,r,sr,sl);



    return 0;

}