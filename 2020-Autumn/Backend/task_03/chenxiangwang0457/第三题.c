#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int f(int** matrix, int n, int m, int target)
{
	int i, j;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (matrix[i][j] == target)
			{
				count = count + 1;
			}
		}
	}
	return count;

}
int main()
{
	int m, n, target;
	scanf("%d%d%d", &n, &m, &target);
	int i, j;
	int** p = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * m);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &p[i][j]);
		}
	}
	int t;
	t = f(p, n, m, target);
	if (t != 0)
	{
		printf("true");
	}
	else if (t == 0)
	{
		printf("false");
	}
	for (i = 0; i < n; i++)
	{
		free(p[i]);
	}
	free(p);
	return 0;
}



