#include<iostream>
using namespace std;

// we have to pass pointer through a argument when there is a alias to pointer to int in the parameter


void swap( int* &x, int* &y)

{ 

int t; 

t = *x;

*x = *y ;

*y = t ;

cout << *x << *y;

}

int main() 

{ int  a, b ;

a = 3 ; b = 5 ;

int *x=&a;
int *y=&b;

swap(x , y);

cout << a << b ;

}