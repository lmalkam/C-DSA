    #include<iostream>
    using namespace std;

    struct trnode
    {
        int data;
        int coeff;
        trnode *next;
    };
    typedef trnode* LPTR;

    void print(LPTR L){
        if(L==NULL)
        return;
        cout<<L->data<<" "<<L->coeff<<" ";
        return print(L->next);
    }

    LPTR findend(LPTR L){
        while(L->next!=NULL)
        L=L->next;
        return L;
    }

    void addend(LPTR &L,int n,int a){
        if(L==NULL){
            L=new(trnode);
            L->data=n;
            L->coeff=a;
            L->next=NULL;
        }
        else{
        LPTR T,E;
        T=new(trnode);
        T->data=n;
        T->coeff=a;
        T->next=NULL;
        E=findend(L);
        E->next=T;}
    }

    void rdelete(LPTR &L,int k){
        if(k==L->data){
            L=L->next;
            return;
        }
        LPTR X=L;
        while(X!=NULL){
        if(X->next->data==k){
            X->next=X->next->next;
        break;
        }
        X=X->next;
        }
    }

    LPTR find(LPTR L,int key){
        
        if(L->data==key)
        return L;
        
        return find(L->next,key);
    }

    int count(LPTR L){
        int c=0;
        while(L!=NULL){
            c++;
            L=L->next;
        }
        return c;
    }

    void addition(LPTR L,LPTR P,LPTR &Q){
        if(L==NULL && P==NULL)
        return;
        if(L==NULL){
            addend(Q,P->data,P->coeff);
            return addition(L,P->next,Q);
        }
        if(P==NULL){
            addend(Q,L->data,L->coeff);
            return addition(L->next,P,Q);
        }
        if(L->coeff==P->coeff ){
        addend(Q,P->data+L->data,P->coeff);
        return addition(L->next,P->next,Q);
        }
        if(L->coeff<P->coeff || L==NULL){
            addend(Q,P->data,P->coeff);
            return addition(L,P->next,Q);
        }
        if(L->coeff>P->coeff || P==NULL){
            addend(Q,L->data,L->coeff);
            return addition(L->next,P,Q);
        }
    }

    int main(){
        

        LPTR P;LPTR R;int a;
        int n;cin>>n>>a;
        P=new(trnode);
        P->data=n;
        P->coeff=a;
        P->next=NULL;
        cin>>n;
        while(n!=-1){
        cin>>a;
        addend(P,n,a);
        cin>>n;
        }
        R=NULL;
        cin>>n;
        while(n!=-1){
            cin>>a;
        addend(R,n,a);
        cin>>n;
        }
        LPTR Q;Q=NULL;
        

        addition(P,R,Q);
        print(Q);

        return 0;
    }                   

