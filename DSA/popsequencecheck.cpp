#include<iostream>
using namespace std;

struct popsequencecheck
{
    int top1;
    int top2;
    int newe[100];
    int elements[5];

};

void push(popsequencecheck &s,int x){
    s.newe[++s.top1]=x;
    return;
}

void push2(popsequencecheck &s,int x){
    s.elements[++s.top2]=x;
    return;
}

int pop(popsequencecheck&s){
    return s.newe[s.top1--];
}

int pop2(popsequencecheck&s){
    return s.elements[s.top2--];
}

int main(){

    popsequencecheck one;
    one.top1=-1;one.top2=0;

    int a[5];
    for(int i=0;i<5;i++)
    cin>>a[i];
    int n,z=1,i=0;
    push2(one,z);
    push(one,a[i]);

    while(z<6){
        if(one.newe[one.top1]==one.elements[one.top2]){
            pop(one);
            pop2(one);
            push(one,a[++i]);
        }
        else{
            push2(one,++z);
        }
    }
     i==5?cout<<"1":cout<<"0";
      
     return 0;
}