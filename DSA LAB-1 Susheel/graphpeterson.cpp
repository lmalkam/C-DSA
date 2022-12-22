#include<iostream>
using namespace std;

int deg[5][5]={0},ind[5]={0};int indeg[5]={0};int n1;int a1[10];

int G[10][10]={{0,1, 0, 1, 1, 0, 0, 0, 0, 0},
               {1,0, 1, 0, 0, 0, 1, 0, 0, 0}, 
               {0,1, 0, 1, 0, 0, 0, 1, 0, 0}, 
               {0,0, 1, 0, 1, 0, 0, 0, 1, 0}, 
               {1,0, 0, 1, 0, 0, 0, 0, 0, 1}, 
               {1,0, 0, 0, 0, 0, 0, 1, 1, 0}, 
               {0,1, 0, 0, 0, 0, 0, 0, 1, 1}, 
               {0,0, 1, 0, 0, 1, 0, 0, 0, 1}, 
               {0,0, 0, 1, 0, 1, 1, 0, 0, 0},
               {0,0, 0, 0, 1, 0, 1, 1, 0, 0},   
            };
int n=0;
bool checker(string s,int i,int path[],int store)
{
    if(i==s.length()){
    path[n++]=s[i-1]-65;
    return true;
    }

    if(G[store][int(s[i])-65]){
        path[n++]=store;
    return checker(s,i+1,path,int(s[i])-65);}

    if(G[store][int(s[i])-60]){
        path[n++]=store;
    return checker(s,i+1,path,int(s[i])-60);}
}

int main(){
    int a,b;
    
    int V[5]={0};

    string s;
    cin>>s;

    int path[10];

    int ans[10];
    int i=0;

    int store;
    if(G[int(s[0])-65][int(s[1])-65])
    store=int(s[0])-65;
    else
    store=int(s[0])-60;

    if(checker(s,1,path,store)){
    for(int i=0;i<n;i++)
    cout<<path[i]<<" ";}
    else 
    cout<<"0"<<endl;

     return 0;
}