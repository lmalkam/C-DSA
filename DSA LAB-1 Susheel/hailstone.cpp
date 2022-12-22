#include <iostream>
using namespace std;

int hailstone(int n, int i)
{

    if (n == 1)
    {
        cout <<"1"<< endl<<i;
        return 0;
    }

     cout<<n<<" ";

    if (n % 2 == 0)
        return hailstone(n/2, i + 1);
    else
        return hailstone(3*n+1, i + 1);
}

int main()
{
    int n;
    cin >> n;

    hailstone(n, 1);
    return 0;
}