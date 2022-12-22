#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trap(vector<int>& height) {

    stack<int> st;int sum=0;

    for(auto i=height.begin();i!=height.end();++i)
    {
        int t;
        if(st.empty()){
        st.push(*i);
        t=*i;
        }
        else if(t<=*i)
        {
            while(!st.empty())
            {
                int x=t-st.top();
                cout<<x<<" ";
                if(x>0)
                sum+=x;
                st.pop();
            }
            st.push(*i);
            t=*i;
        }
        else
        {
            st.push(*i);
        }

    }

    while(!st.empty())
    {
        int t;
        stack<int> stack;
        if(stack.empty()){
        stack.push(st.top());
        t=st.top();
        st.pop();
        }
        else if(t<=st.top())
        {
            while(!stack.empty())
            {
                int x=t-stack.top();
                cout<<x<<" ";
                if(x>0)
                sum+=x;
                stack.pop();
            }
            stack.push(st.top());
            t=st.top();
            st.pop();
        }
        else
        {
            stack.push(st.top());
            st.pop();
        }

        

    }

    return sum;
}

int main(){
    vector<int> h ={0,1,0,2,1,0,1,3,2,1,2,1}; 
    cout<<trap(h);
    return 0;
}