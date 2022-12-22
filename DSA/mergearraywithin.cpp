#include <iostream>
using namespace std;

int main()
{

    int a[99];
    int i=0,n=1,count=0;;
    while(i>=0){
        cin>>a[i];
        if(a[i]==-1)
        count++;
        if(count==2)
        break;
        i++,n++;
    }
    n=n-2;

    int j = 0;
    int b[100] = {0};
    for (int i = 1; i < n ; i = i + 2)
    {
        if (a[i] >= a[i + 1])
        {
            if (a[i] > a[i + 2])
            {
                a[i + 2] = a[i];
                a[i + 1] = a[i - 1];
            }
            else
                a[i + 1] = a[i - 1];

            if (i == n - 1)
            {
                b[j++] = a[i - 1];
                b[j++] = a[i];
            }
        }
        else
        {
            b[j++] = a[i - 1];
            b[j++] = a[i];
        }
    }
    
    for (int i = 0; i < j; i++)
        cout << b[i] << " ";

    return 0;
}