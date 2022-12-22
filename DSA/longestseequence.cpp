#include <iostream>
using namespace std;

int main()
{

    int i = 0, n = 1;
    int a[100];
    while (i >= 0)
    {
        cin >> a[i];
        if (a[i] == -1)
            break;
        i++, n++;
    }
    n--;

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "-1";
        return 0;
    }

    int count = 0, index, z;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            z = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] == 1)
                    z++;
                else
                    break;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == 1)
                    z++;
                else
                    break;
            }

            if (count < z)
            {
                count = z;
                index = i;
            }
        }
    }

    cout << index;

    return 0;
}
