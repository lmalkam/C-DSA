#include <iostream>
using namespace std;

int Indexf(int arr[], int n)
{
    int max_count = 0;
    int max_index = -1;

    int prev_zero_index = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 1)
        {
            count++;
        }

        else
        {

            count = i - prev_zero_index;

            prev_zero_index = i;
        }

        if (count > max_count)
        {
            max_count = count;
            max_index = prev_zero_index;
        }
    }

    return max_index;
}

int main()
{
    int i = 0;
    int arr[100];
    while (i >= 0)
    {
        cin >> arr[i];
        if (arr[i] == -1)
            break;
        i++;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    int index = Indexf(arr, n);

    if (index != -1)
    {
        cout << Indexf(arr, n);
    }
    else
    {
        cout << "-1";
    }

    return 0;
}