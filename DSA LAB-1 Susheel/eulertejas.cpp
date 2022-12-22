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
int arr[50]={0};  int a=0;
int indeg[12]={0};

void print(lptr l){
    while(l!=NULL){
        cout<<l->data+1<<" ";
        l=l->next;
    }
}
void degree()
{
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			indeg[a]+=g[i][j];
		}
		a++;
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
 
void path(int source, int n, lptr &l1){
    for(int i=0; i<n; i++){
        if(g[source][i]==1){
             addend(l1, i);
             g[source][i]=0;
             g[i][source]=0;
             indeg[source]--;
             indeg[i]--;
             path(i, 12, l1);
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
	for(int a=0;a<12;a++){
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
    degree();
    for(int i=0;i<12;i++)
    cout<<indeg[i]<<", ";
    addend(l, 0);
    path(0, n, l);int c=0;
    while(check()){
    	int k=find(l);
    	path(find(l),n,l1[c]);
    	lptr end = findend(l1[c]);
    	lptr start = findnode(l , k);
    	end->next = start->next;
    	start->next = l1[c];
    	c++;
	}
	print(l);

    return 0;
}