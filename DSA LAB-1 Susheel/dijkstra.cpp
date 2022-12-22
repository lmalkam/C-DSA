#include<iostream> 
using namespace std;
int n=0;
int findMin(int dis[], int visited[],int wet[]){
    int min=999;
    int k;
    for(int i=0; i<5; i++){
       if(visited[i]==0){
        if(min>dis[i]){
            min=dis[i];
            k=i;
        }
       }
    }
    return k;
}
void shortest_path(int G[][5], int dis[50], int visited[50], int prev[50], int source, int target,int wet[],int path[]){
      if(source == target)
      return ;
      for(int i=0; i<5; i++){
           if(G[source][i]>0 && visited[i]==0){
              if(dis[source]+G[source][i]+wet[i]<dis[i]){
                  dis[i]=wet[i]+G[source][i]+dis[source];
                  prev[i]=source;
              }
           }
       }
       visited[source]=1;
       int alpha = findMin(dis, visited,wet);
       shortest_path(G, dis,visited, prev, alpha , target,wet,path);
}
int main(){

    int G[5][5] = {0, 2, 8, 5, 0, 
                   0, 0, 1, 0, 0, 
                   0, 0, 0 ,0, 3,
                   0, 0, 0, 0, 4, 
                   0, 0, 0, 0 ,0 ,
                   };
    int visited[5]={0};
    int dis[7];
    for(int i=0; i<5; i++){
        dis[i]=999;
    }
    dis[0]=0;
    int prev[5]={};
    int target=4;
    int source=0;
    int wet[5]={0,1,2,3,4};
    int path[100];
    for(int i=1;i<5;i++){
    shortest_path(G, dis, visited, prev,  source, i,wet,path);
    cout<<dis[i]<<" ";
    }
    cout<<endl;
   
}