#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap(vector<int>& height) {

    stack<int> stack;int sum=0;

    for(auto i=height.begin();i!=height.end();++i)
    {
        cout<<*i<<" ";
    }

    return sum;
}

int main(){
    vector<int> h ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(h);
    return 0;
}