
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int** creatArray(int m, int n)
{
	int i, j;
	int** array, ** pt;
	array = (int**)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
	{
		array[i] = (int*)malloc(n * sizeof(int));
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			array[i][j]=i*n+j+1;
		}
	}
	pt = array;
	return pt;
}
void main() {
	int** p, i, j;
	p = creatArray(3, 3);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
