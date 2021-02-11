#include<stdio.h>
#include<stdlib.h>
int rotate(int** matrix, int n)
{
	int a[15][15],m(0);
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			a[j][n - 1 - i] = *(*matrix + m);
			m++;
		}
	printf_s("输出的结果为：\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%d ", a[i][j]);
		}
		printf_s("\n");
	}
	return 0;
}

int main()
{
	int n(0);
	printf_s("请输入矩阵的边长：");
	scanf_s("%d", &n);
	int* s;
	s = (int*)malloc(n * n * sizeof(int));
	if (s == NULL) exit(1);
	for (int i = 1; i <= n * n; i++)
	{
		printf_s("请输入第%d个数：", i);
		scanf_s("%d", (s + i - 1));
	}
	int** matrix;
	matrix = &s;
	rotate(matrix, n);
	free((int*)s);
	return 0;
}