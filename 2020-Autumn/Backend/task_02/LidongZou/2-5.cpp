#include<stdio.h>
#include<stdlib.h>
int** createArray(int n, int m)
{
	int** a;
	int i, j;
	a = (int**)malloc(sizeof(long int) * n);
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = i * m - m + j;
			printf_s("%d", a[i][j]);
		}
		printf_s("\n");
	}
	return 0;
}