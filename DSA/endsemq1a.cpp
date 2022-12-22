#include <iostream>
#include <cstring>
using namespace std;
struct stack{
    int size;
    int top;
    char elements[50];
};
void push(stack &s, char value){
    if(s.top == s.size-1){
        cout<<"stack is full\n";
    }else{
        s.top+=1;
        s.elements[s.top]=value;
    }
}
char pop(stack &s){
    if(s.top==-1){
        cout<<"stack is empty\n";
    }
    return s.elements[s.top--];
}
char peep(stack &s){
    return s.elements[s.top];
}
void analyse(stack &s, stack &s1, string str){
    int first =0;
    int second = 0;;
    int count;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='}'){
            push(s, str[i]);
            first++;
        }
        if(str[i]=='{'){
            push(s1, str[i]);
            second++;
        }
    }
    if(s.top==-1){
        count=(first+second)/2;
        int i=0;
        while(i<count/2+1){
            cout<<pop(s1);
            i++;
        }
        i=0;
        while(i<count/2+1){
            if(peep(s1)=='{'){
               cout<<"}";
            }
            else{
                cout<<"{";
           }
            i++;
        }
        cout<<" "<<count;
    }
    else if(s.top!=-1 && s1.top!=-1){
        count= first+second;
        while(s1.top!=-1){
            cout<<pop(s1);
        }
        while(s.top!=-1){
            cout<<pop(s);
        }
        cout<<" "<<count;
    }
}
int main()
{
	stack s;
	s.top=-1,
    s.size=100;
	string str;
	cin>>str;
    stack s1;
    s1.top=-1;
    s1.size=-100;
    int x = str.length();
    if(x%2==1){
        cout<<"No";
    }
    else{
    analyse(s, s1, str);
    }
	return 0;
}