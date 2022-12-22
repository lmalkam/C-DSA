#include<iostream>
using namespace std;

int unique(string str,int count,int j)
{
    static int n=str.length();
    if(j==n+1)
    return count;

    if(str[j]!='*')
    count++;

    for(int i=j+1;i<n;i++)
    {
        if(str[j]=='*')
        break;
        if(str[j]==str[i])
        {
            char ch='*';
            str[i]==ch;
        }
    }
    for(int i=0;i<n;i++)
        cout<<str[i];
        cout<<endl;
    

    return unique(str,count,j+1);
}

int main(){

    string s;
    cin>>s;

    cout<<unique(s,0,0);


     return 0;
}
