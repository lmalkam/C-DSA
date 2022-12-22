#include<iostream>
#include<string>
using namespace std;

bool check(string n,string m,int i,int j){

    if(i==n.length()/2)
    return true;

    if(j==m.length()/2)
    return check(n,m,i+1,);

    if(n[i]==m[j])
    return check(n,m,i+1,j-1);

    return false;


}


int main(){
      
      string n,m;

      cin>>n>>m;

      cout<<check(n,m,0,m.length()-1);


     return 0;
}