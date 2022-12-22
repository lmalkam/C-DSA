#include <iostream>
using namespace std;

struct customer
{
    int acc;
    string name;
    int bal;
};

void filter(customer a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i].bal < 100)
        {
            cout << a[i].acc << endl;
            cout << a[i].name << endl;
        }
    }
}

void depwith(customer a[], int n)
{

    int key;

    cout << "Enter acc number : ";
    cin >> key;

    int amount;
    cout << "Enter the amount of money : ";
    cin >> amount;

    for (int i = 0; i < n; i++)
    {
        if (key == a[i].acc)
        {
            int code;
            cout << "Enter the code 1 for deposit and 0 for withdrawal : ";
            cin >> code;

            if (code == 1)
            {
                a[i].acc += amount;
            }

            if (code == 0)
            {
                if (a[i].acc -= amount < 0)
                {
                    cout << "The balance is insufficient for the transaction !";
                    return;
                }
                a[i].acc -= amount;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of customers : ";
    cin >> n;

    customer a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the acc number of " << i + 1 << " :";
        cin >> a[i].acc;
        cout << "Enter the name of " << i + 1 << " ";
        cin >> a[i].name;
        cout << "Enter the balance of " << i + 1 << " ";
        cin >> a[i].bal;
    }

    filter(a, n);

    depwith(a, n);

    return 0;
}