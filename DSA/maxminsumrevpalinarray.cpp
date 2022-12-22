#include <iostream>
using namespace std;

void calculation(int *a, int n, int &max, int &min, int &sum, int &flag)
{

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - 1 - i])
            flag = false;
    }

    for (int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

int main()
{

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max = a[0], min = a[0], sum = 0;
    int flag = 1;

    calculation(a, n, max, min, sum, flag);

    cout << max << " " << min << " " << sum << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    if (flag == true)
        cout << "1";
    else
        cout << "0";

    return 0;
}