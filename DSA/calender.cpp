#include <iostream>
using namespace std;

void S(int *x, int &y, int *&z, int w)

{
     int *t;

     t = &y;

     *x = y + *z;

     y = *z + *t;

     *z = *x + y;

     w = *t + w;

     cout << w << *x << y << *z << endl;
}

int main()

{
     int a = 1, b = 2, *c = new int(3), *d = new int(4);

     S(&a, b, c, *d);

     cout << a << b << *c << *d;
}