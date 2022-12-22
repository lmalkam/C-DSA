#include<iostream>
using namespace std;

struct STree
{
    float avg;
};
STree AT[10000];

struct stack
{
	int f,r,s;
	float E1[20];
};
void equeue(stack &Q ,float x)
{
	if((Q.r+1)%Q.s==Q.f){
		cout<<"full...";
	}
	else{
		if(Q.r==-1){
			Q.r=0;
			Q.f=0;
		}
		else 
		Q.r=(Q.r+1)%Q.s;
		
		Q.E1[Q.r]=x;
	}
}
float dqueue(stack &Q)
{
	float t;
	if(Q.f==-1) cout<<"empty queue...";
	else{
		t=Q.E1[Q.f];
		if(Q.f==Q.r){
			Q.f=-1,Q.r=-1;
		}
		else
		Q.f=(Q.f+1)%Q.s;
		return t;
	}
}

STree consAT(STree AT[],int A[],int si,int l,int r)
{
	if(l==r){
        AT[si].avg=A[r];
		return AT[si];
	}
	int mid=(l+r)/2;
    AT[si].avg=(consAT(AT,A,2*si+1,l,mid).avg+consAT(AT,A,2*si+2,mid+1,r).avg)/(2);
	return AT[si];
}

void levelorder(STree A[],stack Q,float k,int i,int n)
{
    equeue(Q,A[i].avg);
    equeue(Q,k);
    while(Q.f!=-1){
      //  cout<<i<<" ";

        if(i==2*n-1){
            cout<<"/";
        return;}
        float temp=dqueue(Q);
        if(temp==0){
            if(Q.f==-1){
                return;
            }
            else{
                cout<<"/ "<<endl;
                equeue(Q,k);
                continue;
            }
        }
        else cout<<temp<<" ";
        
        if(2*i+1<2*n-1){
            equeue(Q,A[2*i+1].avg);
        }
        if(2*i+2<=2*n-1){
            equeue(Q,A[2*i+2].avg);
        }
        i++;
    }
}


int main()
{
    int i=0,n=0, a[100];
    cin>>a[i++];
	while(i>=0)
    {
        cin>>a[i];
        if(a[i++]==-1)
        break;
    }
    n=i-1;

   
	 int l=0,r=n-1,k,sl,sr;
	
     int si=0;
	 consAT(AT,a,si,l,r);
     float x=0;
     stack q;
     q.f=q.r=-1;
     q.s=100;
     i=0;

     levelorder(AT,q,x,i,n);



    




    return 0;

}