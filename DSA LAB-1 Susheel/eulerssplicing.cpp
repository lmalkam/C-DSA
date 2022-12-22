#include<iostream> 
using namespace std;
struct node{
    int data;
    node *next;
};
typedef node* lptr ;
lptr findend(lptr p){
    while(p->next!= NULL){
        p=p->next;
    }
    return p;
}
void addend(lptr &l, int n){
    if(l==NULL){
         l = new(node);
        l->data = n;
        l->next = NULL; 
    }
    else{
    lptr t ,e;
    t= new(node);
    t->data = n;
    t->next =NULL; 
    e =findend(l);
    e->next = t;
    }
}

int g[12][12]={{0,0,1,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,1,0,0,0,0},{1,1,0,1,0,1,1,0,1,0,0,0},{1,0,1,0,1,0,1,0,0,1,1,0},
			   {0,0,0,1,0,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,0,1,0,0,0},{0,0,1,1,0,0,0,0,1,1,0,0},{0,1,0,0,0,0,0,0,1,0,0,0},
			   {0,0,1,0,0,1,1,1,0,1,0,1},{0,0,0,1,1,0,1,0,1,0,1,1},{0,0,0,1,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,1,0,0}};
int arr[50]={0};  int a=1;
int indeg[12]={2, 2, 6, 6, 2, 2, 4, 2, 6, 6, 2, 2};
void print(lptr l){
    while(l!=NULL){
        cout<<l->data+1<<" ";
        l=l->next;
    }
}
void splice(int x, int n, lptr &l,int c){
    for(int i=0; i<n; i++){
        if(g[x][i]==1){
            addend(l, i);
            g[x][i]=0;
            g[i][x]=0;
            indeg[i]--;
            indeg[x]--;
            splice(i, n, l,c);
            break;
        }
    }
}

int find(lptr l){
    while(l!=NULL){
        if(indeg[l->data]!=0){
            return l->data;
        }
        l=l->next;
    }
    return 0;
}
 
void path(int x, int n, lptr &l1){
    for(int i=0; i<n; i++){
        if(g[x][i]==1){
             addend(l1, i);
             g[x][i]=0;
             g[i][x]=0;
             indeg[x]--;
             indeg[i]--;
             path(i, n, l1);
             break;
        }
    }
}

lptr findnode(lptr l, int k){
    lptr x=l;
    while(x!=NULL){
        if(x->data==k){
            return x;
        }
        x=x->next;
    }
    return NULL;
}

int check()
{
	int flag=0;
	for(int a=0;a<7;a++){
		if(indeg[a]!=0){
			return 1;
		}
	}
	return 0;
}
int main(){

    lptr l=NULL;
    lptr l1[100]={NULL};
    int n=12;
    addend(l, 0);
    path(0, n, l);int c=0;
    while(check()){
    	int k=find(l);
    	splice(find(l),n,l1[c],c);
    	lptr end = findend(l1[c]);
    	lptr start = findnode(l , k);
    	end->next = start->next;
    	start->next = l1[c];
    	c++;
	}
	print(l);

    return 0;
}

/*
0 3
0 2
2 3
1 2
3 4
1 7
2 5
5 8
2 8
2 6
8 6
3 6
6 9
8 9
8 11
11 9
4 9
9 10
3 10
3 9
7 8
-1 -1
*/