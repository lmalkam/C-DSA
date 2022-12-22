#include <iostream> 
using namespace std; 
struct stack{
	int top;
	char elements[20];
	int size;
};
void push(stack &s, char value)
{
	if(s.top==s.size-1){
        cout<<"stack overflow";
    }
    s.top+=1;
    s.elements[s.top]=value;
}
char pop(stack &s)
{
	if(s.top==-1){
        cout<<"stack underflow";
    }
    return s.elements[s.top--];
}
int partition(int arr[], int l, int h) 
{ 
  int x = arr[h]; 
  int i = (l - 1); 
  for (int j = l; j <= h - 1; j++) { 
    if (arr[j] <= x) { 
      i++; 
      swap(arr[i], arr[j]); 
    } 
  } 
  swap(arr[i + 1], arr[h]); 
  return (i + 1); 
} 
void quick_sort(int arr[], int l, int h, stack &s) 
{ 
   push(s, l);
    push(s, h);
  while(s.top >= 0) 
  { 
    h = pop(s); 
    l = pop(s); 
    int p = partition(arr, l, h); 
    if(p-1>l) 
    { 
       push(s, l);
       push(s, p-1);
    } 
    if(p+1<h) 
    { 
      push(s, p+1); 
      push(s, h); 
    } 
  } 
} 
int main() 
{ 
    stack s;
    s.top=-1;
    s.size=50;
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  quick_sort(a,0,n-2,s); 
  for(int i=0;i<n-1;i++)
  {
      cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0; 
}