#include<iostream>
using namespace std;
//2.Ğı×ª¾ØÕó
void rotate(int** matrix, int n)
{
    for (int i = 0; i < n / 2; i++)
        for (int j = 0, k; j < n - 2 * i - 1; j++)
        {
            k = matrix[i][i + j];
            matrix[i][j + i] = matrix[n - 1 - i - j][i];
            matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
            matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
            matrix[i + j][n - 1 - i] = k;
        }
}
int main()
{

	return 0;
}