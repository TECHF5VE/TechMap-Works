#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int i, j;
	for (i = 0;i < matrixSize;i++)
	{
		for (j = i + 1;j < matrixSize;j++)
		{
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	for (i = 0;i < matrixSize;i++)
	{
		for (j = 0;j < matrixSize / 2;j++)
		{
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrixSize - 1 - j];
			matrix[i][matrixSize - 1 - j] = temp;
		}
	}
	return;
}
int main() {
	int** arr;
	int i, j, t = 3;
	int* colmat = (int*)malloc(t * sizeof(int));
	arr = (int**)malloc(t * sizeof(int));
	for (i = 0;i < t;i++)
	{
		*(arr + i) = (int*)malloc(t * sizeof(int));
	}
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	rotate(arr, 3, colmat);
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d,\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
	for (i = 0;i < t;i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(colmat);
}