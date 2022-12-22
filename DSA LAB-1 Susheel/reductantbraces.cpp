#include<iostream>
using namespace std;

struct reductantbraces
{
    int top;
    char ele[100];
};

void push(reductantbraces&s,char x){
    s.ele[++s.top]=x;
    return;
}

char pop(reductantbraces&s){
    return s.ele[s.top--];
}


int main(){
    reductantbraces s;s.top=-1;
    string str;cin>>str;bool flagopen=0;bool flagclose=0;int count=0;int check=0;
    for(int i=0;i<str.length();i++){
        if(count==2 && s.ele[s.top]=='(')
        flagopen=1;
        if(count==2 && s.ele[s.top]==')')
        flagclose=1;
        if(s.ele[s.top]=='(' && str[i]==')' && check==0){
        cout<<"1";
        return 0;
        }
        if(str[i]=='(' || str[i]==')'){
        push(s,str[i]);
        count++;
        }
        else
        count=0;
        if(str[i]=='(')
        check=0;
        if(str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*')
        check++;
    }
    (flagopen==1 && flagclose==1)?cout<<"1":cout<<"0";
     return 0;
}