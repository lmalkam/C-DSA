#include<bits/stdc++.h>
using namespace std;

int comp(int a,int b)
{
    return a*b;
}

void solution(){

    vector<int> v= {1,1,1,4,5};

    v.push_back(6);
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;

    auto it = upper_bound(v.begin(),v.end(),3);
    cout<<*it<<endl;

    auto it2 = lower_bound(v.begin(),v.end(),5);
    cout<<*it2<<endl;

    int sum=accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;

    int mul=accumulate(v.begin(),v.end(),1,comp);
    cout<<mul<<endl;


    unique(v.begin(),v.end());

    for(auto i:v)
    cout<<i<<" ";

    v.resize(4);

    for(auto i:v)
    cout<<i<<" ";



    

}
int main(){
      int t;t=1;
      while(t--)solution();
       
     return 0;
}