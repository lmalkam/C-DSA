#include<iostream>
using namespace std;

struct STree
{
    string value;
    int even;
    int odd;
};

void consST(STree ST[],string A,int si,int l,int r)
{
	if(l==r){
		ST[si].value=A[r];
        return;
	}
	int mid=(l+r)/2;
    int i=l;
    while(i<=r){
    ST[si].value+=A[i++];
    }
	consST(ST,A,2*si+1,l,mid);
    consST(ST,A,2*si+2,mid+1,r);
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

void query1(STree ST[],string &s,int si,int l,int r)
{

    int ind;cin>>ind;
    char ch;cin>>ch;
    s[ind]=ch;
    //cout<<s;
    ST[0].value="";int i=0;
    while(i<r)
    {
        ST[i*2+1].value="";
        ST[i*2+2].value="";
        i++;
    }
    consST(ST,s,0,0,s.length()-1);

}

int distinct(string str)
{
	int a[26]={0}, 
    c=0;
	for(int i=0; i<str.size(); i++)
		a[str[i]-97]+=1;
		
	for(int i=0; i<26; i++)
	{
		if(a[i]>0)
			c++;
	}
	return c;
}

string query2(STree ST[],int si,int sl,int sr,int l,int r)
{
    if(sl>=l && r>=sr)
    {
        return ST[si].value;
    }
    if(sr<l || sl>r)
    {
        return "";
    }
    
    int mid=(sl+sr)/2;
   // static string res="";
    return query2(ST,2*si+1,sl,mid,l,r)+query2(ST,2*si+2,mid+1,sr,l,r);
}
int main()
{
	string s="";int i=0;char ch;
    cin>>ch;
    while(ch!='#')
    {
        s=s+ch;
        i++;
        cin>>ch;
    }

   //- cout<<s;

  //  cout<<i<<endl;

	int l=0,r=i,k;
	
	STree ST[50];
    int si=0;
	consST(ST,s,si,l,i);
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
        int q;
        cin>>q;
        if(q==1)
        {
            query1(ST,s,0,0,r);

        }
        else{
        int a,b;
        cin>>a>>b;
        string final=query2(ST,0,0,r,a,b);
        //cout<<final;
        cout<<distinct(final)<<" ";
        }

    }
    return 0;

}