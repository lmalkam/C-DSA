#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct fixes
{
    int top;int top2;
    string final;
    char ele[100];
    char ch[100];
};


string reverse(string &s){

    for(int i=0;i<s.length()/2;i++){
        int temp=s[i];
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=temp;
    }
    return s;
}

void push(fixes &s, char x){
    s.ele[++s.top]=x;
    return;
}

void push2(fixes &s, char x){
    s.ele[++s.top2]=x;
    return;
}

char pop(fixes &s){
    return s.ele[s.top--];
}

char pop2(fixes &s){
    return s.ch[s.top2--];
}

void priority(fixes &s,char x){

    if(x==')'){
        if(s.ele[s.top]=='(')
        pop(s);
        while(s.top!=-1){
        s.final+=pop(s);
        s.final+=" ";
        }
    }
    if((x=='+' || x=='-') &&  s.ele[s.top]=='*' || s.ele[s.top]=='/'){
           s.final+=pop(s);
           s.final+=" ";
    }
    if(x=='*' || x=='/' || x=='+' || x=='-')
        push(s,x);
}

void priority2(fixes &s,char x){

    if(x==')'){
        while(s.top!=-1){
        if(s.ele[s.top]=='('){
        pop(s);
        break;}
        s.final+=pop(s);
        s.final+=" ";
        }
    }
    if((x=='+' || x=='-') &&  s.ele[s.top]=='*' || s.ele[s.top]=='/'){
           s.final+=pop(s);
           s.final+=" ";
    }
    if(x=='*' || x=='/' || x=='+' || x=='-' || x=='(')
        push(s,x);
}

void priority3(fixes &s,char x){

    if(x=='*' || x=='/' || x=='+' || x=='-')
        push(s,x);

    if(x=='*' || x=='/' || x=='+' || x=='-'){
        s.final+=pop(s)
    }



    /*if(x==')'){
        if(s.ele[s.top]=='(')
        pop(s);
        while(s.top!=-1){
        s.final+=pop(s);
        s.final+=" ";
        }
    }
    if((x=='+' || x=='-') &&  s.ele[s.top]=='*' || s.ele[s.top]=='/'){
           s.final+=pop(s);
           s.final+=" ";
    }
    if(x=='*' || x=='/' || x=='+' || x=='-')
        push(s,x);*/
}

int main(){

      fixes s;s.top=-1;
      
      string s1,s2,s3;
     // getline(cin,s1);
     // getline(cin,s2);
     getline(cin,s3);

      s1=reverse(s1);s.final="";

      for(int i=0;i<s1.length();i++){
            if(s1[i]>='A' and s1[i]<='Z'){
            s.final+=s1[i];s.final+=" ";}
            else
            priority(s,s1[i]);
        }
        while(s.top!=-1){
           s.final+=pop(s);
           s.final+=" ";
        }

       reverse(s.final);
        s1=s.final;

        s.top=-1;s.final="";
        for(int i=0;i<s2.length();i++){
            if(s2[i]>='A' and s2[i]<='Z'){
            s.final+=s2[i];
            s.final+=" ";
            }
            else
            priority2(s,s2[i]);
        }
        while(s.top!=-1)
           s.final+=pop(s);

        cout<<s.final;

        s.top=-1;s.final="";
        s3=reverse(s3);
        for(int i=0;i<s3.length();i++){
            if(s3[i]>='A' and s3[i]<='Z'){
            push(s,s[i]);
            }
            else
            priority3(s,s3[i]);
        }
        while(s.top!=-1)
           s.final+=pop(s);

           cout<<s.final;




      

      /*for(int i=0;i<s1.length();i++){
          if(s1[i]>='A' && s1[i]<='Z')
          s.final+=s1[i];
          if(s1[i]=='*' || s1[i]=='/' || s1[i]=='+' || s1[i]=='-' || s1[i]=='(' || s1[i]==')')
          push(s,s1[i]);

      }*/


     return 0;
}