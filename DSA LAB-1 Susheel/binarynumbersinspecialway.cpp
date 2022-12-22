#include<iostream>
#include<cstring>
using namespace std;

struct stack
{
    int f,r,s;
    string que[100];
};

void enqueue(stack &q,string x){
    if(q.r+1%q.s==q.f)
    cout<<"FULL";
    else{
        if(q.r==-1)
        {
            q.r=0;q.f=0;
        }
        else{
        q.r=(q.r+1)%q.s;
        q.f=0;}
        q.que[q.r]=x;
    }
}

string dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
    else{
        string t=q.que[q.f];
        if(q.r==q.f)
        {
            q.f=-1;
            q.r=-1;
        }
        else
        q.f=(q.f+1)%q.s;
        return t;
    }
}



string reverse(string &s){

    for(int i=0;i<s.length()/2;i++){
        int temp=s[i];
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=temp;
    }
    return s;
}

string binary(int n,string s){
    if(n==0)
    return s;
    s+=to_string(n%2);
    return binary(n/2,s);
}

int main(){

    int n;
    cin>>n;
    stack q;q.f=-1;q.r=-1;

    for(int i=1;i<=n;i++){
        string s=binary(i,"");
        enqueue(q,reverse(s));
    }

    for(int i=1;i<=n;i++){
        cout<<dequeue(q)<<" ";
    }
     return 0;
}