#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> mystack;
        for(int i=0;i<s.length();i++){
            if(mystack.empty()){
                mystack.push(s[i]);
                
            }
            else if ((mystack.top() == '(' && s[i] == ')')
                 || (mystack.top() == '{' && s[i] == '}')
                 || (mystack.top() == '[' && s[i] == ']')){
                mystack.pop();
            }
            else{
                mystack.push(s[i]);
            }
            
        }
        if(mystack.empty()){
            return true;
            
        }
        else{
            return false;
        }
    }

int main(){

    string s = "()[]{}";
    bool flag=isValid(s);
    cout<<flag;
      

     return 0;
}