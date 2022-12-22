#include<bits/stdc++.h>
using namespace std;

struct edgepair{
    int a;
    int b;
    int weight;
};

struct disjointset{
    int *parent;
    int *rank;

    disjointset(int x){
        parent=new int[x];
        rank=new int[x];
        for (int i = 0; i < x; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        else{
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void union_set(int a, int b){
        int x=find(a);
        int y=find(b);
        if(x==y) return;
        else{
            if(rank[x]>rank[y]){
                parent[y]=x;
            }
            else if(rank[x]<rank[y]){
                parent[x]=y;
            }
            else{
                parent[y]=x;
                rank[x]++;
            }
        }
    }
};

bool comparator(edgepair a,edgepair b){
    return (a.weight<b.weight);
}

int G[8][8]={0};

int input(){
    int a,b,c;
    cin>>a>>b>>c;
    while(a!=-1){
        G[a][b]=c;
        G[b][a]=c;
        cin>>a>>b>>c;
    }
}

void makeedgepair(edgepair arr[], int &k){
    for (int i = 1; i < 8; i++){
        for(int j=i; j<8; j++){
            if(G[i][j]!=0){
                arr[k].a=i;
                arr[k].b=j;
                arr[k].weight=G[i][j];
                k++;
            }
        }
    }
}

void kruskals(){
    disjointset d(8);
    edgepair arr[20];
    edgepair ans[20]; int t=0;
    int finalweight=0;
    int k=0;
    makeedgepair(arr,k);
    sort(arr,arr+k-1,comparator);
    for (int i = 0; i < k; i++){
        if(d.find(arr[i].a)!=d.find(arr[i].b)){
            d.union_set(arr[i].a,arr[i].b);
            ans[t]=arr[i];t++;
            finalweight+=arr[i].weight;
        }
    }    
    for (int i = 0; i < t; i++){
        cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].weight<<endl;
    }
    
    cout<<finalweight<<" ";
}

int main(){
    input();
    kruskals();
    return 0;
}