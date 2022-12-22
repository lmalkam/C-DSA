#include <iostream>
#include <cstring>
using namespace std;
void island(int mat[10][10], int newmat[10][10], int x, int y)
{
	if (mat[x + 1][y] == 1 && newmat[x + 1][y] != 1)
	{
		newmat[x + 1][y] = 1;
		island(mat, newmat, x + 1, y);
	}
	if (mat[x - 1][y] == 1 && newmat[x - 1][y] != 1)
	{
		newmat[x - 1][y] = 1;
		island(mat, newmat, x - 1, y);
	}
	if (mat[x][y + 1] == 1 && newmat[x][y + 1] != 1)
	{
		newmat[x][y + 1] = 1;
		island(mat, newmat, x, y + 1);
	}
	if (mat[x][y - 1] == 1 && newmat[x][y - 1] != 1)
	{
		newmat[x][y - 1] = 1;
		island(mat, newmat, x, y - 1);
	}
}
int main()
{
	int mat[10][10] = {{1, 0, 1, 0, 0, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}};
	int newmat[10][10] = {0};
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (newmat[i][j] != 1 && mat[i][j] == 1)
			{
				island(mat, newmat, i, j);
				count++;
			}
			else if (mat[i][j] == 0)
			{
				newmat[i][j] = 1;
			}
		}
	}
	cout << count;
	return 0;
}