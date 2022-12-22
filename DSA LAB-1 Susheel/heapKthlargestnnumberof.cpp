#include<iostream>
using namespace std;

int checkheap(int H[],int n,int i)
{
	if(i<n){
		if(2*i+1<n && 2*i+2<n){
			if(H[i]<H[2*i+1] && H[i]<H[2*i+2]){
				i+=1;
				checkheap(H,n,i);
			}
			else return 0;
		}
	}
	return 1;
}

void heapyup(int H[],int i)
{
    if(i==0)
    return;
    int p=(i-1)/2;
    if(H[p]>H[i])
    {
        swap(H[p],H[i]);
        i=p;
        return heapyup(H,i);
    }
    else
    return;
}

void createheap(int H[],int size,int &n)
{
    if(n<size)
    {
        int k;cin>>k;
        if(k==-1)
        return;
        H[n]=k;
        heapyup(H,n);
        n++;
        createheap(H,size,n);
    }
}

void heapydown(int H[],int i,int n)
{
		int mini,li,ri;
		li=2*i+1;ri=2*i+2;
		mini=i;
		if(H[mini]>H[li] && li<=n) mini=li;
		if(H[mini]>H[ri] && ri<=n) mini=ri;
		swap(H[i],H[mini]);
		if(i!=mini)
		heapydown(H,mini,n);
}

void heapsort(int H[],int n)
{
	if(n==0){
		cout<<H[0];
		return;
	}
	else{
		cout<<H[0]<<" ";
		H[0]=H[n];
		n=n-1;
        heapydown(H,0,n);
		heapsort(H,n);
	}
}

void large(int H[],int k,int &i,int limit){

    if(i==limit+1)
    {
        heapydown(H,0,i);
        if(H[0]<H[i-1]){
        H[0]=H[i-1];
      //  heapyup(H,i-1);
        }
        i--;
        for(int z=0;z<i;z++)
        cout<<H[z]<<" ";
        cout<<endl;
    }

    H[i++]=k;
    if(k==-1)
    return;
    if(i<limit+1){
    for(int z=0;z<i;z++)
    cout<<H[z]<<" ";
    cout<<endl;
    }
    heapyup(H,i);
}


int main(){

      int H[1000];
      int size=100;
      int n=0;int k;
      int l;
      cin>>l;

      cin>>k;
      while(1)
      {
          large(H,k,n,l);
          if(k==-1)
          break;
          cin>>k;
      }

      

    return 0;
}