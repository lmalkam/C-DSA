#include <iostream>
using namespace std;

struct trnode
{
    int data;
    int coeff;
    trnode *next;
};
typedef trnode *LPTR;

void print(LPTR L)
{
    if (L == NULL)
        return;
    cout << L->data << " " << L->coeff << " ";
    return print(L->next);
}

LPTR findend(LPTR L)
{
    while (L->next != NULL)
        L = L->next;
    return L;
}

void addend(LPTR &L, int n, int a)
{
    if (L == NULL)
    {
        L = new (trnode);
        L->data = n;
        L->coeff = a;
        L->next = NULL;
    }
    else
    {
        LPTR T, E;
        T = new (trnode);
        T->data = n;
        T->coeff = a;
        T->next = NULL;
        E = findend(L);
        E->next = T;
    }
}

void rdelete(LPTR &L, int k,int a)
{
    if (k == L->data && a==L->coeff)
    {
        L = L->next;
        return;
    }
    LPTR X = L;
    while (X != NULL)
    {
        if (X->next->data == k && X->next->coeff == a)
        {
            X->next = X->next->next;
            break;
        }
        X = X->next;
    }
}

LPTR find(LPTR L, int key)
{

    if (L->data == key)
        return L;

    return find(L->next, key);
}

int count(LPTR L)
{
    int c = 0;
    while (L != NULL)
    {
        c++;
        L = L->next;
    }
    return c;
}

void cutshort(LPTR &L)
{
    if(L->next==NULL || L==NULL)
    return;

    if((L->next->data==L->data || L->next->coeff==L->coeff)){
        if(L->next->next->data==L->data || L->next->next->coeff==L->coeff){
        L->next=L->next->next;
        return cutshort(L->next);
        }
        else{
            rdelete(L,L->data,L->coeff);
            return cutshort(L);
        }
    }
    return cutshort(L->next);
}

int main()
{

    LPTR P;
    LPTR R;
    int a;
    int n;
    cin >> n >> a;
    P = new (trnode);
    P->data = n;
    P->coeff = a;
    P->next = NULL;
    cin >> n>>a;
    while (n != -1 && a!=-1)
    {
        addend(P, n, a);
        cin >> n>>a;
    }
    
    cutshort(P);
    print(P);

    return 0;
}
