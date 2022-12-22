#include<iostream>
using namespace std;

struct stack
{
    int top;
    char sta[100];
};

void push(stack &s,char x){
    s.sta[++s.top]=x;
    return;
}

char pop(stack &s){
    return s.sta[s.top--];
}

struct stack
{
    int f,r,s;
    char que[100];
};

void enqueue(stack &q,int x){
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

char dequeue(stack &q){
    if(q.f==-1)
    cout<<"Queue is empty";
    else{
        int t=q.que[q.f];
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

void reverse(stack &s,string str){

    int i=0;
    while(str[i]!='#'){
        push(s,str[i++]);
    }

    while(s.top!=-1){
        cout<<pop(s);
    }
}

bool palindrome(stack &q,stack &s,string str){
    int i=0;
    while(str[i]!='#'){
        enqueue(q,str[i++]);
    }
    
    int half=i/2;

    while(q.f!=half){
        push(s,dequeue(q));
    }
    
    while(s.top!=-1){
        if(s.sta[s.top]==q.que[q.f]){
            pop(s);dequeue(q);
        }
        else
        return false;
    }
    return true;
}


int main(){
      
      string str1;
      cin>>str1;string str2;
    cin>>str2;
      stack s;stack q;
      s.top=-1;q.r=-1;q.f=-1;
      int i=-1;

    reverse(s,str1);
    cout<<endl;
    s.top=-1;q.r=-1;q.f=-1;
    cout<<palindrome(q,s,str2);
     return 0;
}