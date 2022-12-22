#include <iostream>
using namespace std;

int G[8][8] = {{0, 1, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 1, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 1, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 1, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 0}, 
               {0, 0, 0, 0, 0, 0, 1, 0}, 
               {0, 0, 0, 0, 0, 0, 0, 1}, 
               {0, 0, 1, 0, 0, 0, 0, 0}};

void topo(int z, int a[], int indeg[], int n)
{
    if (z == n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(a[j]) << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (indeg[i] == 0)
        {
            if(i<5)
            a[n] = i+65;
            else
            a[n]=i+64;
            indeg[i] = -1;
            for (int x = 0; x < 8; x++)
            {
                if (G[i][x] == 1)
                {
                    indeg[x] -= 1;
                }
            }
            topo(z, a, indeg, n + 1);
            indeg[i] = 0;
            for (int x = 0; x < 8; x++)
            {
                if (G[i][x] == 1)
                {
                    indeg[x] += 1;
                }
            }
        }
    }
}

int main()
{
    int x, y;
    int indeg[8] = {0,1,2,1,1,0,1,1};
    
    int a[100];
    int n = 0;

    topo(8, a, indeg, n);

    return 0;
}