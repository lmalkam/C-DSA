#include <iostream>
using namespace std;

int main()
{

    int a[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 9/2; i++)
    {
        for (int j = 9; j >=9/2; j--)
        {
            if (a[i] % 2 != 0 && a[j]%2==0){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
