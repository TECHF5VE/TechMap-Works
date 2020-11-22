#include<stdio.h>
void rotate(int** matrix, int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			matrix[j][n - i + 1];
			printf_s("%d", matrix[j][n - i + 1]);
			printf_s("\n");
		}
	}
}
